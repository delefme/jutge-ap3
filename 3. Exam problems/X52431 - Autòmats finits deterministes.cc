#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n_estats;
    cin >> n_estats;
    if (n_estats > 0) {
        // lectura de les transicions, transicions[i][j] indica a quin
        // estat arribem partint de l'estat j utilitzant el símbol i
        vector<vector<int>> transicions(2, vector<int>(n_estats));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n_estats; j++) {
                cin >> transicions[i][j];
            }
        }
        // lectura dels estats d'acceptació, marca 1 si ho és 0 altr.
        vector<int> acceptacio(n_estats, 0);
        for (int i = 0; i < n_estats; i++) {
            cin >> acceptacio[i];
        }
        int longitud_maxima;
        cin >> longitud_maxima;

        // mem[i][j] conté el nombre de paraules acceptades desde i amb j símbols
        vector<vector<int>> mem(n_estats, vector<int>(longitud_maxima + 1, 0));

        // omplim el cas base (0mov.) per aquells estats d'acceptació
        for (int i = 0; i < n_estats; i++) {
            if (acceptacio[i] == 1) {
                mem[i][0] = 1;
            }
        }

        // omplim la taula mem segons la recurrència de que el nombre de paraules
        // de long. j acceptades començant a un estat i és la suma del nombre de
        // paraules acceptades de longitud j-1 començant als estats als que podem
        // anar des de i amb un símbol.
        for (int j = 1; j <= longitud_maxima; j++) {
            for (int i = 0; i < n_estats; i++) {
                for (int k = 0; k < 2; k++) {
                    mem[i][j] += mem[transicions[k][i]][j - 1];
                }
            }
        }

        // l'estat inicial sempre és el zero
        // escrivim el nombre de paraules acceptades des d'aquest per cada longitud
        for (int j = 0; j <= longitud_maxima; j++) {
            cout << mem[0][j] << endl;
        }
    } else {
        // pel cas on hi ha 0 estats és impossible arribar a un estat d'acceptació
        int len;
        cin >> len;
        for (int i = 0; i < len; i++) {
            cout << 0 << endl;
        }
        // NOTA: he separat aquest cas perquè considero que queda més net
    }
}
