class MoonObject {
    private:
        const double Gravity = 1.625; // Moon's gravitational acceleration (m/s^2)
        double initHeight; // initial height (m)
        double initVerVel; // initial vertical velocity (m/s)
        double HorVel; // horizontal velocity (m/s)
    public:
        MoonObject ();
        MoonObject (double, double, double);
        bool setHeight(double);
        bool setVerVel(double);
        bool setHorVel(double);
        double getXPos(double);
        double getYPos(double);
};