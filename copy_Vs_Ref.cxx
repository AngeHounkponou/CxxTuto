#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void fn_copy(vector<int> vc){
    for (auto &i: vc) {
        i++;
    }
}

void fn_ref(vector<int> &vr){
    for (auto &i: vr) {
        i++;
    }
}

int main(){
    cout<<"Version du C++ : "<<__cplusplus<<"."<<endl;
    vector<int> v{2,4,8,12};

    fn_copy(v);
    /* Afficher les valeurs de v */
    cout<<"Vecteur v apres fn_copy()..."<<endl;
    for (auto i : v) {
        cout<<i<<" ";
    }

    fn_ref(v);
    cout<<"\nVecteur v apres fn_ref()..."<<endl;
    /* Afficher les valeurs de v */
    for (auto i : v) {
        cout<<i<<" ";
    }
    cout<<endl;

    return EXIT_SUCCESS;
}
