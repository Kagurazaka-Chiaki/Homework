#include <iostream>

using namespace std;

int i = 1;

class MyCls {

private:

    int m_n_fir;
    int m_n_sec;
    int m_n_thd;
    int &m_n_for;

public:

    MyCls() : m_n_for(m_n_thd), m_n_sec(i++), m_n_fir(i++), m_n_thd(i++) {
        m_n_thd = i;
    }

    void echo() {
        int temp = m_n_fir + m_n_sec + m_n_thd + m_n_for;
        cout << "result: " << temp << endl;
    }
};

int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */

    MyCls ocls;
    ocls.echo();

    return 0;
}