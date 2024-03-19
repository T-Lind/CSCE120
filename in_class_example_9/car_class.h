class Car {
    public:
        int seats;

        void init_color(char * newcolor);
        void print_car();
        void set_power_in_hp(int hp);
        int get_power_in_hp() const;

        Car(); // Default constructor
        Car(char* c, int hp, int s);
    
    private:
        char color[20];
        double power;          // in kw

        //const double conversion_factor = 0.74569987; 
    
        //double convert_hp_to_kw(int hp);
        //int convert_kw_to_hp(int hp);

};