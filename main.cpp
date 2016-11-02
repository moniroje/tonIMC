#include <iostream>

// Quel est ton indice de masse corporelle?

using namespace std;

int main()
{
    string nom("chais pas");
    // ne pas oublier le ; !!! sinon, ERROR
    // tout ce qu'on déclare doit être utilisé sinon ERROR
    int poids, taille; // déclare les variables: age poids en kg & taille en cm

    // commentons AAAAAAAAAAAAAAAAAAAAAAAAA pour BBBBB  ou CCCCCCCCCCCCCC
     cout << "Salut!! comment tu t'appelles? " << endl;
     cin >> nom;  // là, il tape son nom
    // endl crée un retour à la ligne dans la console
     cout << " Tu pèses combien ?? rien que les kilos, stp "; cin >> poids;
     cout << "Ta taille, en centimètres ? "; cin >> taille;
    /* attention, dans ta formule de imc, taille ne peut être = 0, puisque au dénominateur; prévoir donc
     * le cas où l'utilisateur tape zéro: */
      if (taille == 0)
       {
        cout << " Les êtres plus petits que un centimètre vont à la poubelle"<< endl;
        cout << "Veuillez taper un autre nombre que zéro, s'il-vous-plaît"<< endl;
        cin >> taille ;
       }
      if (poids == 0)
      {
        cout << " Etre immatériel, que viens-tu faire ici ? "<< endl;
        cout << " Arrête de faire l'idiot: ton poids, en kilos "<< endl;
        cin >> poids ;
      }

     // BBBBBBBBBBBBBBBB essayons avec la boucle while
     // BBBBBBBBBBBBBBBBBBBBB while (taille*poids == 0)
        //Pour qu'un produit soit nul, il suffit qu'un de ses termes le soit!
       // BBBBBBBBBBBBBBBBB {
       // BBBBBBBBBBBBBBBBBBBB  cout << " Tu mesures combien ?? dis ta hauteur en centimètres, stp" << endl; cin >> taille;
       // BBBBBBBBBBBBBBBB  cout << " En kilos, indique ton poids s'il-te-plaït" <<endl; cin >> poids;
         // ici, quand on tape 0 à taille ou à poids, il te repose la question jusqu'à ce que tu tapes autre chose
       // BBBBBBBBBBBBBBBBBBBBBBBBBBB  }

       // CCCCCCCCCCCCCCCC essai de la boucle do while
       // CCCCCCCCCCCCCCC do
       // CCCCCCCCCCCCCCCC  {
         // CCCCCCCCCCCCCC cout << "What is your height ?? with cm, please  " << endl; cin >> taille;
         // CCCCCCCCCCCCCC cout << "an your wheight? kilos only"  << endl; cin >> poids;
        // CCCCCCCCCCCCCCC  }
       // CCCCCCCCCCCCCCC while ( !taille * poids );
       /* d'après les explications de linux 5623:
        * do tu fais la boucle. while, tu sors de la boucle; pour cela il faut que la condition (!taille*poids)
        * soit vraie: valeur true. Si taille ou poids = 0, le produit sera =0
        * Maintenant voyons le point d'exclamation: c'est un opérateur bool de négation: !true == false
        * Notre produit taille*poids donne un résultat int (ou double): ce qui est true
        * Donc !taille*poids est false; et donc tu sors de la boucle: ça, c'est moi qui comprends linux5623
        * linux5623: Les types int et bool se convertissent comme ci:
        * un int == 0 vaut true et un int != 0 vaut false
        * Dans notre cas l'opérateur convertira le double en bool.
        * S'il est différent de zéro il vaudra du coup false sinon true.
        * Mouais: vachement tiré par les cheveux! */

    // calcul de l'IMC = Poids/taille au carré
    double imc(0); // je déclare cette variable qui risque d'être avec virgule
    int tailleAuCarre(100); // je déclare encore pour faire:
    tailleAuCarre = taille * taille ;/* j'aurais pu utiliser resultat = pow (a,n) ; pour a à la puissance n, sans
    oublier #include<cmath>; en tout cas, là, ça fait l'opération. */
    // imc = poids/tailleAuCarre;
    // par contre, imc = ça n'a pas marché quand j'ai fait: */
    // cout << imc << endl; / commentons lignes 25 & 27 et explications des maîtres droggo, leternel et Médinoc:
    /* maître droggo: Tes 2 variables poids et tailleAuCarre étant des int, la division est faite comme division
     * entière (dans laquelle, par exemple 5/2 => 2).
     * Il faut écrire imc = double(poids)/tailleAuCarre pour quelle se fasse dans le type double: */
     // imc = double(poids)*10000/tailleAuCarre ; / ça marche; à commenter si tu essayes ligne 37 ou ligne39
    /* maître leternel:ton expression ligne 25 correspond en fait à: imc = ( poids / tailleAuCarre );
     * poids et tailleAuCarre étant des int, la division donne un int, qui ne connait pas les virgules.
     * Le langage ne passera aux nombres à virgules flottantes que si tu convertis l'un des opérandes de ce type.
     * Il convient donc de procéder à une conversion qui peut s'écrire ainsi: */
     // imc = static_cast<double>(poids)*10000 / tailleAuCarre;  // à commenter si tu essayes droggo ou Médinoc
     /* maître Médinoc: tu peux aussi faire la conversion sans cast, en forçant une  opération avec un double: */
    imc = poids * 10000 * 1.0 /tailleAuCarre;
    // ce qui me plaît le + de par sa simplicité

     cout <<"Cher(e) "<< nom << " ton IMC est de " <<imc<< endl;
    /* mais je voudrais varier la réponse selon le résultat:donc usons de else if pour ces résultats qui vont être
     * lus dans l'ordre jusqu'à ce que l'un d'eux soit vérifié */
    /* ce qui signifie pour ma tête de lard ceci: CHAQUE ELSE IF VA ETRE EFFECTUÈ À PARTIR DU PREMIER ELSE IF
     * JUSQU'À CE QUE L'UN D'EUX, ELSE IF,  SOIT VÉRIFIÉ.
     * linux5623: if ( condition ) { instruction } else { instruction }
     * La clause else étant facultative.
     * La condition doit être une expression qui revoie 0 pour faux et différent de 0 pour vrai ! */
    // essayons un imc irréaliste:
     if (imc <= 10.1)
     {
         cout << " Hey!!! logori !!" << endl;
     // message curieux: Hey logori !! mais aussi Dénutrition ??
     }
     if (imc <= 16.5)  // préférable à (16.5<=imc)
     {
         cout << "Dénutrition" << endl;
     }
     else if (imc<=18.5)  // si imc < 16.5, la boucle s'est arrêtée à Dénutrition
     {
         cout << "T'es maigre!! "<< endl;
     }
     else if (imc<=21.75)  // si imc <= 18.75 , ça a eu droit déjà à "t'es maigre!! "
     {
         cout << "Svelte, mince, t'es top !! " << endl;
     }
     else if (imc<=25)
     {
        cout << "C'est parfait! T'es trop! "<< endl;
     }
     else if (imc<27.5)
     {
         cout << "Enrobé (ou rondelette) mais bon! attention à ta gourmandise! "<< endl;
     }
     else if (imc <=30)
     {
         cout << "t'es en surpoids; corrige!!! "<< endl;
     }
     else if (imc <35)
     {
         cout << "là, ça devient de l'obésité; attention!! "<< endl;
     }
     else if (imc <40)
     {
         cout << "Obésité sévère "<< endl;
     }
      else if (imc < 46)
     {
         cout << " Obésité morbide ou massive"<< endl;
     }
     // essayons ceci:
     else if (imc>46)
     {
         cout << " Là tu déconnes à donf! "<< endl;
     }
     else
        {
            cout <<"chais pas quoi te dire; salut!"<< endl;
        }
    /* ci-dessous selon le corrigé: je crois comprendre que c'est pour celui que ça
     * n'intéresse pas: */
    // cout << "Appuyez sur une touche pour continuer." << endl;
    /* on appuie sur une touche, ça la tape et c'est tout... bizarre!
     * donc je commente l99 et l102 & 103
    cin.ignore();
    cin.get();
    */
    //  return 0 ;
    /* Cette fonction main() doit renvoyer un entier (puisque de type int) pour
     * signaler si elle a été menée à bien ou non au système d'exploitation...
     * La valeur de cet entier est 0 si ca c'est bien passé (il existe une constante
     * EXIT_SUCCESS, qui vaut elle aussi 0) */
    // return EXIT_SUCCESS; ben non, ça m'a envoyé: ERROR: 'EXIT_SUCCESS' was not declared in this scope; donc:

    return 0;
}
