/*

DICTIONARY and AUTOCOMPLETE using Trie

*/

#include <iostream>
#include <stdio.h>
#include<conio.h>
#include<fstream>
#include <stdlib.h>
#include <cstring>
#include <windows.h>
#include <time.h>
#include <dos.h>                                            //  Importing all the necessary Libraries
using namespace  std;

const int n = 26;                                           // Maximum nodes in Level - 26

struct Node                                                 // Creating a node
{
    struct Node *links[n];
    string meaning;
    string antonym;
    string synonym;                                         // Storing the meaning of the word
    bool iswordend;                                         // To make sure that it is  a word
};

class Trie
{
    struct Node *root = new Node();

public:

    struct Node * getNode();                                // Get Node
    int insert(string, string, string, string);            // Inserting a word in the dictionary ( Trie )
    bool search(string);
    void display_meaning(string);
    void get_antonym(string word);
    void get_synonym(string word);
    bool islastnode(struct Node *);
    void printauto(struct Node * , string);
    int suggestion(string);                          // Displaying the meaning of the word
};

struct Node * Trie :: getNode()
{
    struct Node * n = new Node();

    n -> iswordend = false;

    for(int i = 0 ; i < 26 ; i++)
    {
        n -> links[i] = NULL;
    }
    return n;
}

int Trie :: insert(string word , string mean, string syno, string anto)
{
    struct Node *temp = root;

    int i;

    for(i = 0 ; i < word.length(); i++)
    {
        int ind = word[i] - 'a';
        if(temp -> links[ind] == NULL)
        {
            temp -> links[ind] = getNode();
        }
        temp = temp -> links[ind];
    }
    temp -> meaning = mean;
    temp -> synonym = syno;
    temp -> antonym = anto;
    temp -> iswordend = true;


    return 0;
}

bool Trie :: islastnode(struct Node * root)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(root -> links[i])
        {
            return 0;

        }
    }
    return 1;
}

void Trie :: printauto(struct Node * root , string word)
{
    if(root -> iswordend)
    {
        cout << "\t" << word << endl;
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(root -> links[i])
        {
            char c = 'a' + i;
            printauto(root -> links[i] , word+c);
        }
    }
}

int Trie :: suggestion(string word)
{
    struct Node * temp = root;
    for(char c : word)
    {
        int ind = c - 'a';
        if(temp -> links[ind] == NULL)
        {
            return 0;
        }
        temp = temp -> links[ind];
    }

    if(islastnode(temp))
    {
        cout<<word<<endl;
        return -1;
    }

    printauto(temp , word);
    return 1;
}

bool Trie :: search(string word)
{
    struct Node * temp = root;

    for(int i = 0 ; i < word.length() ; i++)
    {
        int ind = word[i] - 'a';
        if(temp -> links[ind] == NULL)
        {
            return false;
        }
        temp = temp -> links[ind];
    }
    return (temp -> iswordend);
}

void Trie :: display_meaning(string word)
{
    if(search(word))
    {
       struct Node * temp = root;

        for(int i = 0 ; i < word.length() ; i++)
        {
            int ind = word[i] - 'a';
            temp = temp -> links[ind];
        }

        cout << endl;
        cout << "\tMeaning : " << temp -> meaning << endl;
        cout << "\tSynonym : " << temp -> synonym << endl;
        cout << "\tAntonym : " << temp -> antonym << endl;
    }
    else
    {
        cout << "Word not found" << endl;
    }
}

void Trie :: get_antonym(string word)
{
    if(search(word))
    {
       struct Node * temp = root;

        for(int i = 0 ; i < word.length() ; i++)
        {
            int ind = word[i] - 'a';
            temp = temp -> links[ind];
        }

        cout << endl;
        cout << "\tAntonym : " << temp -> antonym << endl;
    }

    else
    {
        cout << "\tWord not found" << endl;
    }
}

void Trie :: get_synonym(string word)
{
    if(search(word))
    {
       struct Node * temp = root;

        for(int i = 0 ; i < word.length() ; i++)
        {
            int ind = word[i] - 'a';
            temp = temp -> links[ind];
        }

        cout << endl;
        cout << "\tSynonym : " << temp -> synonym << endl;
    }

    else
    {
        cout << "\tWord not found" << endl;
    }
}

int main()
{
    int choice;
    string word_input, meaning_input, antonym_input, synonym_input;

    Trie obj;

    string temp ;
    ifstream fin("Dictionary.csv");
    string line;
    string arr[4];

    while(fin)
    {
        int i = 0;
        temp = '\0';

        getline(fin,line);

        for(int j = 0 ; j < line.length() ; j++ )
        {
            if(line[j] != ',')
            {
                temp = temp + line[j];
            }
            else
            {
                string word;

                for(int k = 0 ; k < temp.length();k++)
                {
                    if(temp[k] != '\0')
                    {
                        word = word + temp[k];
                    }
                }

                arr[i] = word;
                i++;
                temp = '\0';
            }
        }

        obj.insert(arr[0],arr[1],arr[2],arr[3]);
    }
    fin.close();


    system("color 0F0");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tDictionary and Autocomplete";
    Sleep(2000);                                                                           // sleep
    system("cls");

    while( choice != 4 )
    {
        system("cls");
        cout << endl << endl;
        printf("\n\t\t\t\t\t    *********************** ||   Welcome user !  || ***********************  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                         1. Dictionary                               *  ");
        printf("\n\t\t\t\t\t    *                         2. Autocomplete                             *  ");
        printf("\n\t\t\t\t\t    *                         3. About us                                 *  ");
        printf("\n\t\t\t\t\t    *                         4. Exit                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    **************************  ||  -------  ||  **************************  ");


        printf("\n\n\n\t\t\t\t\tEnter your choice: ");
        cin  >> choice;

        if( choice == 1)
            {
                while (choice != 6)
                {
                    system("cls");
                    cout << endl << endl;
                    printf("\n\t\t\t\t\t    *********************** ||   Welcome user !  || ***********************  ");
                    printf("\n\t\t\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t\t\t    *                         1. Insert Word                              *  ");
                    printf("\n\t\t\t\t\t    *                         2. Search Word                              *  ");
                    printf("\n\t\t\t\t\t    *                         3. Get Antonym                              *  ");
                    printf("\n\t\t\t\t\t    *                         4. Get Synonym                              *  ");
                    printf("\n\t\t\t\t\t    *                         5. Get all Words                            *  ");
                    printf("\n\t\t\t\t\t    *                         6. Main Menu                                *  ");
                    printf("\n\t\t\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t\t\t    **************************  ||  -------  ||  **************************  ");

                    printf("\n\n\n\t\t\t\t\tEnter your choice: ");
                    cin  >> choice;

                    if ( choice == 1 )
                    {
                        char con;

                        system("cls");
                        cin.ignore();
                        cout << "\n\n\tEnter the following : " << endl;
                        cout << "\n\tWord : ";
                        getline(cin, word_input);
                        for(int i = 0 ; i < word_input.length() ; i++)
                        {
                            word_input[i] = tolower(word_input[i]);
                        }
                        cout << "\tMeaning : ";
                        getline(cin, meaning_input);
                        for(int i = 0 ; i < meaning_input.length() ; i++)
                        {
                            meaning_input[i] = tolower(meaning_input[i]);
                        }
                        cout << "\tSynonym : ";
                        getline(cin, synonym_input);

                        for(int i = 0 ; i < synonym_input.length() ; i++)
                        {
                            synonym_input[i] = tolower(synonym_input[i]);
                        }
                        cout << "\tAntonym : ";
                        getline(cin, antonym_input);
                        for(int i = 0 ; i < antonym_input.length() ; i++)
                        {
                            antonym_input[i] = tolower(antonym_input[i]);
                        }

                        ofstream fout("Dictionary.csv",ios :: app);

                        if(!obj.search(word_input))
                        {
                            fout << word_input << ',' << meaning_input << ',' << synonym_input << ',' << antonym_input << ',' << ' ';
                            fout << endl;

                            obj.insert(word_input, meaning_input, synonym_input, antonym_input);
                        }

                        else
                        {
                            cout<<"\n\n\tThe Word is already added in the dictionary !"<<endl;
                        }

                        cout<<"\n\tPress 'enter' to continue"<<endl;


                        do
                        {
                            con = getch();
                        }while(con != 13);
                    }

                    else if ( choice == 2)
                    {
                        char con;

                        system("cls");
                        cout << "\n\tEnter the word to Search for : ";
                        cin  >> word_input;

                        for(int i = 0 ; i < word_input.length() ; i++)
                        {
                            word_input[i] = tolower(word_input[i]);
                        }

                        if(obj.search(word_input))
                        {
                            cout << "\n\n\tYes, The Word is present in the dictionary !" << endl;
                            obj.display_meaning(word_input);


                        }

                        else
                        {
                            cout << "\n\n\tThe word is not yet added in the Dictionary !" << endl;

                        }

                            cout<<"\n\tPress 'enter' to continue"<<endl;

                        do
                        {
                            con = getch();
                        }while(con != 13);
                        }

                    else if ( choice == 3)
                    {
                        char con;

                        cin.ignore();
                        system("cls");
                        cout << "\n\tEnter the word to get antonym for : ";
                        cin  >> word_input;

                        for(int i = 0 ; i < word_input.length() ; i++)
                        {
                            word_input[i] = tolower(word_input[i]);
                        }

                        obj.get_antonym(word_input);

                        cout<<"\n\tPress 'enter' to continue"<<endl;

                        do
                        {
                            con = getch();
                        }while(con != 13);
                    }

                    else if ( choice == 4)
                    {
                        char con;

                        cin.ignore();
                        system("cls");
                        cout << "\n\tEnter the word to get Synonym for : ";
                        cin  >> word_input;

                        for(int i = 0 ; i < word_input.length() ; i++)
                        {
                            word_input[i] = tolower(word_input[i]);
                        }

                        obj.get_synonym(word_input);


                        cout<<"\n\tPress 'enter' to continue"<<endl;
                        do
                        {
                            con = getch();
                        }while(con != 13);
                    }

                    else if ( choice == 5)
                    {
                        char con;

                        system("cls");
                        int lineno1 = 0;
                        string temp ;
                        ifstream fin("Dictionary.csv");
                        string line;
                        string arr[4];

                        while(getline(fin,line))
                        {
                            lineno1++;
                            int i = 0;
                            temp = '\0';

                            for(int j = 0 ; j < line.length() ; j++ )
                            {
                                if(line[j] != ',')
                                {
                                    temp = temp + line[j];
                                }
                                else
                                {
                                    string word;

                                    for(int k = 0 ; k < temp.length();k++)
                                    {
                                        if(temp[k] != '\0')
                                        {
                                            word = word + temp[k];
                                        }
                                    }

                                    arr[i] = word;
                                    i++;
                                    temp = '\0';
                                }
                            }

                            cout <<"----------------------------"<< endl;
                            cout <<"\tWord      : " << arr[0] << endl;
                            cout <<"\tMeaning   : " << arr[1] << endl;
                            cout <<"\tSynonyms  : " << arr[2] << endl;
                            cout <<"\tAntonyms  : " << arr[3] << endl << endl;
                        }

                        cout << "\n\n\t\tTotal Words : " << lineno1 << endl;

                        cout<<"\n\tPress Enter to continue"<<endl;
                        do
                        {
                            con = getch();
                        }while(con != 13);

                        fin.close();
                    }

                    else if ( choice == 6)
                    {
                        system("cls");
                        break;
                    }
                }
        }

        else if ( choice == 2 )
        {
            char con;

            string autoWord;
            system("cls");
            printf("\n\n\n\t\t\t\t\tEnter the word you want to Autocomplete for : ");
            cin  >> autoWord;

            for(int i = 0 ; i < autoWord.length() ; i++)
            {
                autoWord[i] = tolower(autoWord[i]);
            }

            int comp = obj.suggestion(autoWord);

            if (comp == -1)
                cout << "No other strings found with this prefix\n";

            else if (comp == 0)
                cout << "No string found with this prefix\n";

            cout<<"Press 'enter' to continue"<<endl;
            do
            {
                con = getch();
            }while(con != 13);
        }

        else if ( choice == 3 )
        {
            char con;

            system("cls");
            cout << "\n\n\n\tHi ! This is Parthasarathi and Sanjay Ram founders of this dictionary" << endl;
            cout << "\tHope our Dictionary and Autocomplete works ;)" << endl;
            cout << "\n\tThis Dictionary uses Trie Data structure" << endl;

            cout << "\n\tWhy Trie? : ";

            cout << "\n\n\t\t1. With Trie, we can insert and find strings in O(L) time where L represent the length of a single word.";
            cout << "\n\t\t2. This is obviously faster than BST. This is also faster than Hashing because of the ways it is implemented.";
            cout << "\n\t\t3. Another advantage of Trie is, we can easily print all words in alphabetical order which is not easily possible with hashing.";
            cout << "\n\t\t4. We can efficiently do prefix search (or auto-complete) with Trie.";

            cout<<"\n\n\n\tPress 'enter' to continue"<<endl;
            do
            {
                con = getch();
            }while(con != 13);
        }

        else if ( choice == 4 )
        {
            system("color 0F0");
            system("cls");
            cout << "\n\n\n\n\t\t\t\t Exiting";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);

            system("cls");
            cout << "\n\n\n\n\t\t\t\t Exiting";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);

            cout << "\n\n\n\n\n";

            return 0;
        }
    }

    return 0;
}

/*

References :

1. GeekforGeeks     ( Website )
2. Tutorial Point   ( Website )
3. w3schools        ( Website )

*/
