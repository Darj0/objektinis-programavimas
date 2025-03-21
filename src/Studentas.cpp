#include "Studentas.h"
void galutinis_balas_vid(vector<Studentas>& studentai)
{
    for (auto& student : studentai)
    {
        double suma = 0;
        for (int nd : student.nd)
        {
            suma += nd;
        }

        double vidurkis_nd = suma / student.nd.size() ;
        student.galutinis = (vidurkis_nd*0.4 + student.egz*0.6);
    }
}

//---------------------------------------------------
void galutinis_balas_vid_list(list<Studentas>& studentai_list)
{
    for (auto& student : studentai_list)
    {
        double suma = 0;
        for (int nd : student.nd)
        {
            suma += nd;
        }

        double vidurkis_nd = suma / student.nd.size();
        student.galutinis = (vidurkis_nd * 0.4 + student.egz * 0.6);
    }
}






//---------------------------------------------------

void galutinis_balas_med(vector<Studentas>& studentai)
{
   for (auto& student : studentai)
    {

        sort(student.nd.begin(), student.nd.end());

        double mediana;
        int size = student.nd.size();


        if (size % 2 == 0)
        {
            mediana = (student.nd[size / 2 - 1] + student.nd[size / 2]) / 2.0;
        }

        else
        {
            mediana = student.nd[size / 2];
        }


        student.galutinis = (mediana * 0.4 + student.egz * 0.6);
    }
}
//-------------------------------------------------------
void galutinis_balas_med_list(list<Studentas>& studentai_list)
{
    for (auto& student : studentai_list)
    {
        sort(student.nd.begin(), student.nd.end());

        double mediana;
        int size = student.nd.size();

        if (size % 2 == 0)
        {
            mediana = (student.nd[size / 2 - 1] + student.nd[size / 2]) / 2.0;
        }
        else
        {
            mediana = student.nd[size / 2];
        }

        student.galutinis = (mediana * 0.4 + student.egz * 0.6);
    }
}



//-------------------------------------------------------
void print_results(const vector<Studentas>& studentai)
{
    cout << left
         << setw(10) << "Pavarde"
         << setw(10) << "Vardas"
         << setw(15) << "Vid."
         << setw(15) << "Med."
         << setw(20) << "Adresas"
         << setw(10) << "Zingsnis" << endl;

    cout << setfill('-')
         << setw(80) << "-"
         << setfill(' ') << endl;

    const Studentas* previous_student = nullptr;

    for (const auto& studentas : studentai) {
        cout << left
             << setw(10) << studentas.pavarde
             << setw(10) << studentas.vardas;

        if (studentas.reikalavimas == "vid") {
            cout << setw(15) << fixed << setprecision(2) << studentas.galutinis
                 << setw(15) << "-----"
                 << setw(20) << &studentas;
        } else if (studentas.reikalavimas == "med") {
            cout << setw(15) << "-----"
                 << setw(15) << fixed << setprecision(2) << studentas.galutinis
                 << setw(20) << &studentas;
        }

        if (previous_student) {
            ptrdiff_t zingsnis = reinterpret_cast<const char*>(&studentas) - reinterpret_cast<const char*>(previous_student);
            cout << setw(10) << zingsnis;
        } else {
            cout << setw(10) << "-----";
        }

        cout << endl;
        previous_student = &studentas;
    }
}

//----------------------------------------------------------------------------
void print_results_list(const list<Studentas>& studentai_list)
{
    cout << left
         << setw(10) << "Pavarde"
         << setw(10) << "Vardas"
         << setw(15) << "Vid."
         << setw(15) << "Med."
         << setw(20) << "Adresas"
         << setw(10) << "Zingsnis" << endl;

    cout << setfill('-')
         << setw(80) << "-"
         << setfill(' ') << endl;

    const Studentas* previous_student = nullptr;

    for (const auto& studentas : studentai_list) {
        cout << left
             << setw(10) << studentas.pavarde
             << setw(10) << studentas.vardas;

        if (studentas.reikalavimas == "vid") {
            cout << setw(15) << fixed << setprecision(2) << studentas.galutinis
                 << setw(15) << "-----"
                 << setw(20) << &studentas;
        } else if (studentas.reikalavimas == "med") {
            cout << setw(15) << "-----"
                 << setw(15) << fixed << setprecision(2) << studentas.galutinis
                 << setw(20) << &studentas;
        }

        if (previous_student) {

            ptrdiff_t zingsnis = abs(reinterpret_cast<const char*>(&studentas) - reinterpret_cast<const char*>(previous_student));
            cout << setw(10) << zingsnis;
        } else {
            cout << setw(10) << "-----";
        }

        cout << endl;
        previous_student = &studentas;
    }
}
//----------------------------------------------------------------------------
    string capitalize(string var)
    {
    if (!var.empty()) {
        var[0] = toupper(var[0]);
        for (size_t i = 1; i < var.length(); ++i) {
            var[i] = tolower(var[i]);
        }
    }
    return var;
    }
//----------------------------------------------------------------------------
    string tolowers(string var)
    {
    if (!var.empty()) {
          for (size_t i = 0; i < var.length(); ++i) {
            var[i] = tolower(var[i]);
        }
    }
    return var;
    }

//--------------------------------------------------------------------------------
void duomenys(vector<Studentas>& studentai)
{

int studentuSkaicius;

    while (true) {
        cout << "Kiek studentu norite ivesti? \n";
        cin >> studentuSkaicius;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite tik skaiciu): \n";
        } else {
            break;
        }
    }


    for (int i = 0; i < studentuSkaicius; i++) {
        Studentas naujasStudentas;
        cout << "Iveskite studento varda: ";
        cin >> naujasStudentas.vardas;
        naujasStudentas.vardas = capitalize(naujasStudentas.vardas);
        cout << "Iveskite studento pavarde: ";
        cin >> naujasStudentas.pavarde;
        naujasStudentas.pavarde = capitalize(naujasStudentas.pavarde);

        string atsakymas;
        cout << "Ar jau zinote kiek pazymiu noryte ivesti? ('Taip'  'Ne'  'G' - Generuoja pazymius)\n";
        cin >> atsakymas;
        atsakymas = tolowers(atsakymas);

       while (atsakymas != "taip"  && atsakymas !=  "ne"&& atsakymas != "g" )
        {
        cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite 'Taip' arba 'Ne' arba 'G'): \n";
        cin >> atsakymas;
        atsakymas = tolowers(atsakymas);
        }


       if (atsakymas == "taip") {
        int nd_count;
        while (true) {
            cout << "Kiek namu darbu ivertinimu norite ivesti? \n";
            cin >> nd_count;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite tik skaiciu): \n";
            }
            else
            {
                cout << "Iveskite namu darbu ivertinimus (atskiriant ENTER): \n";
                for (int j = 0; j < nd_count; j++)
                {
                    int nd_verte;

                    while (true)
                    {
                        cin >> nd_verte;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                        } else if (nd_verte < 1 || nd_verte > 10) {
                            cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                        } else {
                            naujasStudentas.nd.push_back(nd_verte);
                            break;
                        }
                    }
                }
                break;
            }
        }
    }

        else if (atsakymas == "ne" )
        {
            cout << "Iveskite namu darbu ivertinimus (baigus iveskite '0'): \n" << endl;
            int input;

            while (true)
            {
                cin >> input;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite tik skaiciu): \n";
                }

                else if (input == 0)
                {
                break;
                }
                else if (input < 1 || input > 10)
                {
                    cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                }
                else
                {
                naujasStudentas.nd.push_back(input);
                }
            }
        }

        else if (atsakymas == "g")
        {
            int nd_count = rand() % 5 + 3;
            cout << "Generuojami " << nd_count << " namu darbu ivertinimai: ";
            for (int j = 0; j < nd_count; j++) {
                int nd_verte = rand() % 10 + 1;
                naujasStudentas.nd.push_back(nd_verte);
                cout << nd_verte << " ";
            }
            cout << endl;

            naujasStudentas.egz = rand() % 10 + 1;
            cout << "Generuojamas egzamino ivertinimas: " << naujasStudentas.egz << endl;
        }


        if  (atsakymas != "g")
        {
            cout << "Iveskite egzamino ivertinima: ";
            while (true)
                    {
                        cin >> naujasStudentas.egz;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                        } else if (naujasStudentas.egz < 1 || naujasStudentas.egz > 10) {
                            cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                        } else {
                            naujasStudentas.nd.push_back(naujasStudentas.egz);
                            break;
                        }
                    }

        }
        else{}

        cout << "Galutinio balo skaiciavimui norite naudoti vidurki ar mediana? (Iveskite 'vid' arba 'med'  )"<< endl;

        cin >> naujasStudentas.reikalavimas;
        naujasStudentas.reikalavimas = tolowers(naujasStudentas.reikalavimas);

        while (naujasStudentas.reikalavimas != "vid" && naujasStudentas.reikalavimas != "med")
        {
        cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite vid arba med): ";
        cin >> naujasStudentas.reikalavimas;
        naujasStudentas.reikalavimas = tolowers(naujasStudentas.reikalavimas);
        }

        studentai.push_back(naujasStudentas);


    }


   for (auto& studentas : studentai) {
        if (studentas.reikalavimas == "vid") {
            galutinis_balas_vid(studentai);
        } else if (studentas.reikalavimas == "med" ) {
            galutinis_balas_med(studentai);
        }
    }

}
//----------------------------------------------------
void duomenys_list(list<Studentas>& studentai_list) {
    int studentuSkaicius;

    while (true) {
        cout << "Kiek studentu norite ivesti? \n";
        cin >> studentuSkaicius;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite tik skaiciu): \n";
        } else {
            break;
        }
    }

    for (int i = 0; i < studentuSkaicius; i++) {
        Studentas naujasStudentas;
        cout << "Iveskite studento varda: ";
        cin >> naujasStudentas.vardas;
        naujasStudentas.vardas = capitalize(naujasStudentas.vardas);
        cout << "Iveskite studento pavarde: ";
        cin >> naujasStudentas.pavarde;
        naujasStudentas.pavarde = capitalize(naujasStudentas.pavarde);

        string atsakymas;
        cout << "Ar jau zinote kiek pazymiu norite ivesti? ('Taip'  'Ne'  'G' - Generuoja pazymius)\n";
        cin >> atsakymas;
        atsakymas = tolowers(atsakymas);

        while (atsakymas != "taip" && atsakymas != "ne" && atsakymas != "g") {
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite 'Taip' arba 'Ne' arba 'G'): \n";
            cin >> atsakymas;
            atsakymas = tolowers(atsakymas);
        }

        if (atsakymas == "taip") {
            int nd_count;
            while (true) {
                cout << "Kiek namu darbu ivertinimu norite ivesti? \n";
                cin >> nd_count;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite tik skaiciu): \n";
                } else {
                    cout << "Iveskite namu darbu ivertinimus (atskiriant ENTER): \n";
                    for (int j = 0; j < nd_count; j++) {
                        int nd_verte;
                        while (true) {
                            cin >> nd_verte;
                            if (cin.fail() || nd_verte < 1 || nd_verte > 10) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                            } else {
                                naujasStudentas.nd.push_back(nd_verte);
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        } else if (atsakymas == "ne") {
            cout << "Iveskite namu darbu ivertinimus (baigus iveskite '0'): \n";
            int input;
            while (true) {
                cin >> input;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite tik skaiciu): \n";
                } else if (input == 0) {
                    break;
                } else if (input < 1 || input > 10) {
                    cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                } else {
                    naujasStudentas.nd.push_back(input);
                }
            }
        } else if (atsakymas == "g") {
            int nd_count = rand() % 5 + 3;
            cout << "Generuojami " << nd_count << " namu darbu ivertinimai: ";
            for (int j = 0; j < nd_count; j++) {
                int nd_verte = rand() % 10 + 1;
                naujasStudentas.nd.push_back(nd_verte);
                cout << nd_verte << " ";
            }
            cout << endl;
            naujasStudentas.egz = rand() % 10 + 1;
            cout << "Generuojamas egzamino ivertinimas: " << naujasStudentas.egz << endl;
        }

        if (atsakymas != "g") {
            cout << "Iveskite egzamino ivertinima: ";
            while (true) {
                cin >> naujasStudentas.egz;
                if (cin.fail() || naujasStudentas.egz < 1 || naujasStudentas.egz > 10) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Klaida! Iveskite skaiciu nuo 1 iki 10: \n";
                } else {
                    break;
                }
            }
        }

        cout << "Galutinio balo skaiciavimui norite naudoti vidurki ar mediana? (Iveskite 'vid' arba 'med')\n";
        cin >> naujasStudentas.reikalavimas;
        naujasStudentas.reikalavimas = tolowers(naujasStudentas.reikalavimas);

        while (naujasStudentas.reikalavimas != "vid" && naujasStudentas.reikalavimas != "med") {
            cout << "Klaidingas ivedimas, bandykite dar karta (Iveskite vid arba med): ";
            cin >> naujasStudentas.reikalavimas;
            naujasStudentas.reikalavimas = tolowers(naujasStudentas.reikalavimas);
        }

        studentai_list.push_back(naujasStudentas);

    }


    for (auto& studentas : studentai_list) {
        if (studentas.reikalavimas == "vid") {
            galutinis_balas_vid_list(studentai_list);
        } else if (studentas.reikalavimas == "med") {
            galutinis_balas_med_list(studentai_list);
        }
    }
}

//----------------------------------------------------
void skaityti(vector<Studentas>& studentai, string name, string kriterijus) {
    ifstream fin;




    try {
        fin.open(name);
        if (!fin.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo.");
        }
    } catch (const ifstream::failure& e) {
        cerr << "Nepavyko atidaryti failo: " << name << endl;
        cerr << "Klaida: " << e.what() << endl;
        return;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return;
    }



    try {

        string ignore;
        getline(fin, ignore);
        string line;


        while (getline(fin, line)) {
            istringstream iss(line);
            Studentas stud;
            string vardas, pavarde;

            if (!(iss >> vardas >> pavarde)) {
                cerr << " " << endl;
                continue;
            }

            stud.vardas = vardas;
            stud.pavarde = pavarde;

            int pazymys;
            vector<int> pazymiai;
            while (iss >> pazymys) {
                pazymiai.push_back(pazymys);
            }

            if (!pazymiai.empty()) {
                stud.egz = pazymiai.back();
                pazymiai.pop_back();
                stud.nd = pazymiai;
            }

            studentai.push_back(stud);
        }

        fin.close();
    } catch (const ifstream::failure& e) {
        cerr << "Nepavyko nuskaityti failo: " << e.what() << endl;
        cerr << "Klaida: " << e.what() << endl;


    }
    string reikalavimas = kriterijus;


    for (auto& studentas : studentai) {
        studentas.reikalavimas = kriterijus;
    }

    if (kriterijus == "vid") {
        galutinis_balas_vid(studentai);
    } else if (kriterijus == "med") {
        galutinis_balas_med(studentai);
    }
}
//----------------------------------------------------
void skaityti_list(list<Studentas>& studentai_list, string name, string kriterijus) {
    ifstream fin;

    try {
        fin.open(name);
        if (!fin.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo.");
        }
    } catch (const ifstream::failure& e) {
        cerr << "Nepavyko atidaryti failo: " << name << endl;
        cerr << "Klaida: " << e.what() << endl;
        return;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return;
    }

    try {
        string ignore;
        getline(fin, ignore);
        string line;

        while (getline(fin, line)) {
            istringstream iss(line);
            Studentas stud_list;
            string vardas, pavarde;

            if (!(iss >> vardas >> pavarde)) {
                cerr << " " << endl;
                continue;
            }

            stud_list.vardas = vardas;
            stud_list.pavarde = pavarde;

            int pazymys;
            list<int> pazymiai;
            while (iss >> pazymys) {
                pazymiai.push_back(pazymys);
            }

            if (!pazymiai.empty()) {
                stud_list.egz = pazymiai.back();
                pazymiai.pop_back();
                stud_list.nd.assign(pazymiai.begin(), pazymiai.end());
            }

            studentai_list.push_back(stud_list);
        }

        fin.close();
    } catch (const ifstream::failure& e) {
        cerr << "Nepavyko nuskaityti failo: " << e.what() << endl;
        cerr << "Klaida: " << e.what() << endl;
    }

    string reikalavimas = kriterijus;


    for (auto& studentas : studentai_list) {
        studentas.reikalavimas = kriterijus;
    }


    if (kriterijus == "vid") {
        galutinis_balas_vid_list(studentai_list);
    } else if (kriterijus == "med") {
        galutinis_balas_med_list(studentai_list);
    }
}





//------------------------------------------------------
void patikrinimas(vector<Studentas>& studentai)
{



    cout << left
         << setw(15) << "Pavarde"
         << setw(15) << "Vardas"
         << setw(6)  << "ND1"
         << setw(6)  << "ND2"
         << setw(6)  << "ND3"
         << setw(6)  << "ND4"
         << setw(6)  << "ND5"
         << setw(10) << "Egzaminas"
         << endl;
    cout << string(60, '-') << endl;


    for (const auto& studentas : studentai) {
        cout << left
             << setw(15) << studentas.pavarde
             << setw(15) << studentas.vardas;


        for (const auto& pazymys : studentas.nd) {
            cout << setw(6) << pazymys;
        }


        cout << setw(10) << studentas.egz << endl;
    }


}

//------------------------------------------------------
bool compare_students(const Studentas& a, const Studentas& b) {
    if (a.pavarde == b.pavarde) {
        return a.vardas < b.vardas;
    }
    return a.pavarde < b.pavarde;
}
//--------------------------------------------------

void sort_students(vector<Studentas>& studentai) {
    sort(studentai.begin(), studentai.end(), compare_students);
}
//--------------------------------------------------
string exec(const char* cmd) {
    array<char, 128> buffer;
    string result;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

