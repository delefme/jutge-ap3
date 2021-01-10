#include <iostream>
#include <vector>
using namespace std;

int n, m;
int e_restants = 0;

vector<int> e;
vector<int> p;


void write_output(vector<int>& presi, vector<int>& favor, vector<int>& abstencio, vector<int>& contra) {
  cout << "President de";
  for (int partit : presi) cout << " " << partit;
  cout << endl;
  cout << "A favor";
  for (int partit : favor) cout << " " << partit;
  cout << endl;
  cout << "Abstencio";
  for (int partit : abstencio) cout << " " << partit;
  cout << endl;
  cout << "En contra";
  for (int partit : contra) cout << " " << partit;
  cout << endl << endl;
}



void escriu_configuracions(int i, vector<int>& presi, vector<int>& favor, vector<int>& abstencio, vector<int>& contra, int Min, int Max, int e_favor, int e_contra, int e_restants) {
  if (i == n) {
    if (e_favor > e_contra) write_output(presi, favor, abstencio, contra);
    return;
  }
  if (e_favor + e_restants < e_contra) return;  // prune
  /*      no estan inicialitzats   ó       poden entrar a favor/abstencio      */
  if ( (Max == -1 && Min == 1001) || (abs(Max-p[i]) <= m && abs(Min-p[i]) <= m) ) {
    /* els cardo a favor; actualitzo e_favor, e_restants, presi*/
    favor.push_back(i);
    e_favor += e[i];
    e_restants -= e[i];
    /* actualitzo presi copiant-lo per poder desfer el canvi despres de la crida */
    vector<int> presi_aux = presi;
    if (presi.size() == 0 || e[presi[0]] < e[i]) {
      presi_aux = {i};
    } else if (e[presi[0]] == e[i]) {
      presi_aux.push_back(i);
    }

    /* crido recursivament i+1, min, max */
    escriu_configuracions(i+1, presi_aux, favor, abstencio, contra, min(Min, p[i]), max(Max, p[i]), e_favor, e_contra, e_restants);

    /* desfaig els canvis */
    favor.pop_back();
    e_favor -= e[i];
    e_restants += e[i];


    /* els enxufo a abstencio; actualitzo e_restants */
    abstencio.push_back(i);
    e_restants -= e[i];
    /* crido recursivament i+1, min, max */
    escriu_configuracions(i+1, presi, favor, abstencio, contra, min(Min, p[i]), max(Max, p[i]), e_favor, e_contra, e_restants);
    /* desfaig els canvis */
    abstencio.pop_back();
    e_restants += e[i];
  }

  /* si o si els el foto a contra; actualitzo e_contra, e_restants */
  contra.push_back(i);
  e_contra += e[i];
  e_restants -= e[i];
  /* crido recursivament i+1 */
  escriu_configuracions(i+1, presi, favor, abstencio, contra, Min, Max, e_favor, e_contra, e_restants);
  /* desfaig els canvis */
  contra.pop_back();
  e_contra -= e[i];
  e_restants += e[i];
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int es, pe;
    cin >> es >> pe;
    e_restants += es;
    e.push_back(es);
    p.push_back(pe);
  }
  cin >> m;


  /* vectors de partits segons la seva postura */
  vector<int> favor;
  vector<int> abstencio;
  vector<int> contra;
  vector<int> presi;

  /* Primera crida:
        * i = 0 (primer partit que tracto)
        * presi, favor, abstencio, contra, inicialment buits
        * Min comença a 1001 pq el maxim valor de p[i] es 1000 per tot i
        * Max comença a -1 pq tot p[i] ≥ 0
        * e_favor, e_contra  comencen a 0.
        * e_restants comença amb el total d'escons calculat mentre llegim dades.
   */
  escriu_configuracions(0, presi, favor, abstencio, contra, 1001, -1, 0, 0, e_restants);
}
