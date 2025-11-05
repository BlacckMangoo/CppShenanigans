#include <iostream>
#include <stack>
#include <memory>

class ICommand {
public:
     virtual ~ICommand() = default;
     virtual void Execute() = 0;
     virtual void Undo() = 0;
};

class Jump : public ICommand {
public:
     void Execute() override {
          std::cout << "Executing Jump\n";
     }
     void Undo() override {
          std::cout << "Undo Jump\n";
     }
};

class MoveRight : public ICommand {
public:
     void Execute() override {
          std::cout << "Executing Move Right\n";
     }
     void Undo() override {
          std::cout << "Undo Move Right\n";
     }
};

class Invoker {
private:
     std::stack<std::unique_ptr<ICommand>> history;
     std::stack<std::unique_ptr<ICommand>> redoStack;

public:
     void ExecuteCommand(std::unique_ptr<ICommand> cmd) {
          cmd->Execute();
          redoStack = {}; // clear redo stack on new action
          history.push(std::move(cmd));
     }

     void Undo() {
          if (history.empty()) return;
          auto cmd = std::move(history.top());
          history.pop();
          cmd->Undo();
          redoStack.push(std::move(cmd));
     }

     void Redo() {
          if (redoStack.empty()) return;
          auto cmd = std::move(redoStack.top());
          redoStack.pop();
          cmd->Execute();
          history.push(std::move(cmd));
     }
};

int main() {
     Invoker invoker;
     invoker.ExecuteCommand(std::make_unique<Jump>());
     invoker.ExecuteCommand(std::make_unique<MoveRight>());
     invoker.Undo();
     invoker.Redo();
}
