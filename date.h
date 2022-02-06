class Date {
    int GetMonth();
    int GetDay();
    int GetYear();
    bool Set(int m, int d, int y);

    int Compare(const Date& d);
    friend bool validDate(int month, int day);
public:
    Date();
    Date(int m, int d, int y);
    void Increment(int numDays = 1);
    void Show();
    bool SetFormat(char f);

private:
    char format; //format for date, either default, 2 digit or long
    int month, year, day;
};