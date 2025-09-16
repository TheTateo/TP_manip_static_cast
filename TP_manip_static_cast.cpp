// TP_manip_static_cast.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>

using namespace std;

class Note {
public:
	virtual void afficher() { cout << "Note générique" << endl; }
};
class NoteSur20 : public Note {
	float valeur;
public:
	NoteSur20(float v) : valeur(v) {}
	void afficher() override { cout << "Note sur 20 : " << valeur << endl; }
	float getValeur() { return valeur; }
};

int main()
{
	// Conversion simple
	float note = 10.12;

	cout << note << endl;
	int note_convertie = static_cast<int>(note);
	cout << note_convertie << endl;

	// Conversion dans un tableau
	vector<int> notes;
	int taille_tab;

	cout << "Entrer la taille du tableau : ";
	cin >> taille_tab;
	for (size_t i = 0; i < taille_tab; i++)
	{
		float temp_notes;
		cout << "Entrer une note (/20) :";
		cin >> temp_notes;
		notes.push_back(static_cast<int>(temp_notes));
	}

	// Utilisation d’un indice pour parcourir le vecteur vect
	for (int i = 0; i < notes.size(); i++)
		cout << "vect[" << i << "] = " << notes[i] << '\n';
	cout << '\n';

	// Conversion affichage en pourcentage
	for (int i = 0; i < notes.size(); i++)
		cout << "Note : " << notes[i] << " (soit " << static_cast<double>(notes[i]) /20 * 100 << "%)" << endl;
	cout << '\n';

	// Conversion dans une hiérarchie de classes
	NoteSur20* note20 = new NoteSur20(12.7);
	Note* ptr_note = note20;

	ptr_note->afficher();
	NoteSur20* cast_note = static_cast<NoteSur20*>(ptr_note);
	cout << "Note reelle : " << cast_note->getValeur() << endl;

	delete note20;

	return 0;
}