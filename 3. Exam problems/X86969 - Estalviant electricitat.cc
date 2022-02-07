#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct moli {
    int autonomia;
    int productivitat;
    int consum;
    double ratio_kg_kw; // representa el ratio de kg/kw per cada hora
};
bool comparador_de_molins(moli a, moli b)
{
    return a.ratio_kg_kw > b.ratio_kg_kw;
}

// Estratègia utilitzada: fins que no quedi satisfeta la demanda farem servir el molí que ens doni millor
// productivitat en relació al seu cost energètic mentre duri la seva autonomia, si s'esgota l'autonomia
// passarem a utilitzar el següent millor molí en termes del ratio mencionat productivitat(kg/h)/cost(kw/h)
int main()
{
    int n_molins;
    while (cin >> n_molins) {
        vector<moli> molins(n_molins);

        // llegim les dades completes d'autonomia, productivitat i consum per cada molí dins el vector
        for (int i = 0; i < n_molins; i++) {
            cin >> molins[i].autonomia;
        }
        for (int i = 0; i < n_molins; i++) {
            cin >> molins[i].productivitat;
        }
        for (int i = 0; i < n_molins; i++) {
            cin >> molins[i].consum;
            molins[i].ratio_kg_kw = ((molins[i].productivitat * 1.0) / (molins[i].consum * 1.0)); // (kg/h)/(kw/h)
        }
        int demanda;
        cin >> demanda;
        double min_energia = 0;
        sort(molins.begin(), molins.end(), comparador_de_molins);
        int moli_actual = 0;

        while (demanda != 0) {

            if (demanda - molins[moli_actual].productivitat * molins[moli_actual].autonomia <= 0) {
                // el molí satisfà la demanda restant per si sol
                double hores_necessaries = (demanda * 1.0) / (molins[moli_actual].productivitat * 1.0);
                min_energia += hores_necessaries * molins[moli_actual].consum;
                demanda = 0;

            } else {
                // no satisfà la demanda al complert, produïm el màxim que puguem amb l'autonomia
                demanda -= molins[moli_actual].productivitat * molins[moli_actual].autonomia;
                min_energia += molins[moli_actual].autonomia * molins[moli_actual].consum;
                moli_actual++;
            }
        }
        cout.setf(ios::fixed);
        cout.precision(4);
        cout << min_energia << endl;
    }
}
