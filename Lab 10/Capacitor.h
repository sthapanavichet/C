class Capacitor {
    private:
        double capacitance;
        double voltage;
        double current;
    public:
        Capacitor(double);
        double GetCurrent(double, double);
};