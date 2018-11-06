class route
{
private:
    char *start;
    char *finish;
    int number;
public:
    route();
    route(const route &arg);
    route(char *strt, char *fnsh, int nmbr);
    friend istream& operator >> (istream&, route&);
    friend ostream& operator << (ostream&, route&);
    bool vivod(char *punkt);
    bool Bubble_sort(route element);
    ~route();
};
