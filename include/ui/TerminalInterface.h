namespace Familiar {

class TerminalInterface {
public:
    void run();

private:
    void showTitle() const;
    void showMenu() const;
    int readMenuChoice();
    bool handleChoice(int choice);
};

} // namespace Familiar