#ifndef CINTN_H
#define CINTN_H

class CIntN
{
public:
    CIntN();
    CIntN(int);
    CIntN(int, int);
    CIntN(const CIntN&);
    ~CIntN();
    CIntN operator+(const CIntN&);
    CIntN operator-(const CIntN&);
    CIntN& operator=(const CIntN&);
    friend std::ostream& operator<<(std::ostream &out, const CIntN &tmp);
    friend std::istream& operator>>(std::istream &in, CIntN &);
    friend bool operator==(const CIntN&, const CIntN&);
    int GetN();
private:
    char *num;
    int N;
};


#endif
