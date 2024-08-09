class EarthObject {
    private:
        const double Gravity = 9.81; // Earth's gravitational acceleration (m/s^2)
        double initHeight; // initial height (m)
        double HorVel; // horizontal velocity (m/s)
    public:
        EarthObject ();
        EarthObject (double, double);
        bool setHeight(double);
        bool setHorVel(double);
        double getXPos(double);
        double getYPos(double);
};