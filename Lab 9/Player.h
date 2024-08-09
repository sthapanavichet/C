class Player {
    private:
        std::string name;
        int money;
        int *cards;
        int numCards;
    public:
        Player();
        Player(std::string);
        std::string GetName();
        void DrawCards(int);
        void StealCards(Player&);
        int SumCards();
        bool AddCash(int);
        void Report();
};