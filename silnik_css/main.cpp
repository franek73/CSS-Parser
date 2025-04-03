#include <iostream>
#include <conio.h>
#include "String.h"
#include "Vector.h"
#include "SectionList.h"
#include "Attribute.h"
#include "Selector.h"
using namespace std;

#define STRING_N 200

void Add_Attributes_To_Section(SectionList* section_list) {
    String s;
    char ch[STRING_N], c;
    ch[0] = '\0';
    int y = 0, j = 0, k=0, i=0;
    Attribute current_attribute;
    do
    {
            int sign = (char)getchar();
            c = (char)sign;
            if (c == ':')
            {
                ch[i] = '\0';
                s.SetString(ch);
                current_attribute.name=s;
                k++;
                y++;
                i = 0;
                
            }
            else if (sign == '\n' || sign == '\t')
            {
                ch[i] = '\0';
                i = 0;

            }
            else if (c == ';')
            {
                ch[i] = '\0';
                s.SetString(ch);
                current_attribute.value=s;
                section_list->Add_New_Attribute(current_attribute);
                j++;
                k = 0;
                i=0;
                
            }
            else if (c == '}')
            {
                if (y != j)
                {
                    ch[i] = '\0';
                    s.SetString(ch);
                    current_attribute.value=s;
                    section_list->Add_New_Attribute(current_attribute);
                   
                }
                y = 0;
                j = 0;
                i = 0;
               
                return;
            }
            else if (c==' ')
            {
                if (k == 1) k++;
                else if (k > 1) {
                    ch[i] = ' ';
                    i++;
                }
                
            }
            else
            {
                ch[i] = c;
                ch[i + 1] = '\0';
                i++;
                
            }
        
    } while (c != '}');

}

void If_Command(String s, SectionList* section_list, int& is_command) {
    char ch[STRING_N];
    ch[0] = '\0';
    String s1, s2;
    Attribute current_attribute;
    if (s == "****")
    {
        is_command = 0;
        cout << endl;
    }
    if (s == "?")
    {
        section_list->Number_Of_Sections();
        cout << endl;

    }
    else {
        int index_first = 0, index_last = 0, i = 0, number_of_points = 0, first_stop = 0, second_stop = 0, is_first_number = 1, is_second_number = 1, digit;
        char command = '\0';
        while (s[i] != '\0')
        {
            if (number_of_points == 0 && s[i] == ',')
            {
                first_stop = i;
                int j = 0, m = 1;
                while (j < first_stop)
                {
                    digit = (int)s[j] - 48;
                    if (digit < 0 || digit>9)
                    {
                        is_first_number = 0;
                        break;
                    }
                    index_first = index_first*m + digit;
                    if (m == 1)
                    {
                        m=10;
                    }
                    j++;
                   
                }
                if (is_first_number == 0)
                {
                    j = 0;
                    while (j < first_stop)
                    {
                        ch[j] = s[j];
                        j++;
                    }
                    ch[j] = '\0';
                    s1.SetString(ch);
                }
                number_of_points = 1;
            }
            else if (number_of_points == 1 && s[i] == ',')
            {
                second_stop = i+1;
                int k = second_stop, m=1;
                while (s[k] != '\0')
                {
                    digit = (int)s[k] - 48;
                    if (digit < 1 || digit>9)
                    {
                        is_second_number = 0;
                        break;
                    }
                    index_last = index_last*m + digit;
                    if (m == 1)
                    {
                        m=10;
                    }
                    k++;
                  
                }
                if (is_second_number == 0)
                {
                    int j = 0,
                    k = second_stop;
                    while (s[k] != '\0')
                    {
                        ch[j] = s[k];
                        k++;
                        j++;
                    }
                    ch[j] = '\0';
                    s2.SetString(ch);
                    
                }
                number_of_points = 2;
            }
                else if (number_of_points == 1)
                {
                    command = s[i];
                }
                else if (number_of_points == 2 && i>3)
                {
                    if (is_first_number == 1 && is_second_number == 1 && command == 'S')
                    {
                            section_list->Name_Of_Selector_By_Indexes(index_first, index_last, s);
                      

                    }
                    else if (is_first_number == 0)
                    {
                        if (command == 'S' && s2 == "?")
                        {
                            section_list->Number_Of_Selectors_By_Name(s, s1);
                        }
                        if (command == 'A' && s2 == "?")
                        {
                            section_list->Number_Of_Attributes_By_Name(s, s1);
                        }
                       if (command == 'E')
                        {
                            section_list->Value_Of_Attribute_By_Selector(s1, s2, s);
                        }
                        

                    }
                    else if (is_first_number == 1 && s2 == "*" && command == 'D')
                    {
                            section_list->Delete_Section(s, index_first);
                      
                    }
                    else if (is_first_number == 1)
                    {
                        s2;
                        if (command == 'S' && s2 == "?")
                        {
                            section_list->Number_Of_Selectors_By_Index(index_first, s);
                        }
                        else if (command == 'A' && s2=="?")
                        {
                            section_list->Number_Of_Attributes_By_Index(index_first, s);
                        }
                        else if (command == 'A' )
                        {
                            section_list->Value_Of_Attribute_By_Index(index_first, s, s2);
                        }
                        if (command == 'D')
                        {
                            section_list->Delete_Attributte_By_Section(s, s2, index_first);
                        }

                    }
                 
                    break;
                }
                i++;
            
        }
    }
}
int main()
{
    String s, s1;
    char ch[STRING_N], c;
    ch[0] = '\0';
    int is_command = 0, is_selector=0, sign = 0, i = 0;
    SectionList* section_list = new SectionList;
    Vector<String> current_selectors;
    Attribute current_attribute;
    c = (char)sign;

    while (c != '\xff')
    {
        sign = (char)getchar();
        c = (char)sign;
        if (c == ',')
        {
            if (is_command == 0)
            {
                ch[i] = '\0';
                s.SetString(ch);
                current_selectors.Add_New_Element(s);
                i = 0;
                is_selector = 0;
            }
            else
            {
                ch[i] = c;
                ch[i + 1] = '\0';
                i++;
            }
        }
        else if (c == '{')
        {
            if (ch[i - 1] == ' ')
            {
                ch[i - 1] = '\0';
            }
            ch[i] = '\0';

            s.SetString(ch);
            if (i != 0)
            {

                current_selectors.Add_New_Element(s);
                section_list->Add_New_Section();
                section_list->Copy_Selectors(current_selectors);
                current_selectors.Clear();
                Add_Attributes_To_Section(section_list);

            }
            else {
            section_list->Add_New_Section();
            Add_Attributes_To_Section(section_list);
        }
            i = 0;

        }
        else if (c == ' ')
        {
            if (is_selector == 1)
            {

                ch[i] = ' ';
                ch[i + 1] = '\0';
                i++;
            }
 

        }
        else if (sign == '\n' || c == '\t' || c== '\xff')
        {
            if (is_command == 1)
            {

                ch[i] = '\0';
                s.SetString(ch);
                If_Command(s, section_list, is_command);
                i = 0;
            }

        }
        else if (sign < 32)
        {

        }
        else
        {
            ch[i] = c;
            ch[i + 1] = '\0';
            s.SetString(ch);
            i++;
            is_selector = 1;
        }


        s.SetString(ch);
        if (s == "????")
        {
            ch[0] = '\0';
            s.SetString(ch);
            is_command = 1;
            i = 0;
        }
     
    }

    return 0;
}

