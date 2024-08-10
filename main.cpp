#include <iostream>
#include <cstring>

//template <typename T, std::size_t N>
void printm(const unsigned char*mass,size_t size) /*, unsigned int lenght_string*/
{
    //печать массива
    for(int i=0;i<size;i++) //добавить в функцию аркумент - кол-во символов в строке
    {
        printf("%02x ",mass[i]);

        if(i==9)
            std::cout << std::endl;

        if(i>10 && i%10==9)
            std::cout << std::endl;    
    }
        //std::cout << std::endl;
}

int main() {
    
    /*
    * данные на вход
    */
   
   //генерация массива
    int mass_element = 100;
    unsigned char *mass = new unsigned char[mass_element];
    // char mass[100] = {0};

    //srand(time(0));

    for(int i=0;i<mass_element;i++)
    {
        mass[i] = rand()%100; //максимальное значение элемента sizeof<type data>???
    }

    //добавление паттернов повторений
    /*int number_of_inclusion = 3; //количество повторений
    int lenght_of_pattern = 5; //длинна патерна
    unsigned char *test_pattern = new unsigned char[lenght_of_pattern];*/

    //srand(time(0));
    /*for(int i=0;i<lenght_of_pattern;i++)
    {
        test_pattern[i] = rand()%100;
    }*/

    //printm(test_pattern,lenght_of_pattern);

    /* pattern[0] = 0xAA;
    pattern[1] = 0xAA;
    pattern[2] = 0xAA;
    pattern[3] = 0xAA;
    pattern[4] = 0xAA; */
   
    //получение позиций включения
    /*unsigned char *inclusion_index = new unsigned char[number_of_inclusion];
    inclusion_index[0] = 10;
    inclusion_index[1] = 40;
    inclusion_index[2] = 70;*/

    //размещение включений
    /*memcpy(mass+inclusion_index[0],test_pattern,5);
    memcpy(mass+inclusion_index[1],test_pattern,5);
    memcpy(mass+inclusion_index[2],test_pattern,5);*/

    mass[5] = 0x29;
    mass[6] = 0x43;

    mass[11] = 0x29;
    mass[12] = 0x43;

    mass[5] = 0xAA;
    mass[6] = 0xBB;
    mass[7] = 0xCC;

    mass[87] = 0xAA;
    mass[88] = 0xBB;
    mass[89] = 0xCC;

    //вывод созданного массива
    printm(mass,mass_element);

    /*
    * поиск паттернов повторений
    */
    //инициализация хранилища паттерна повторений
    
    int lenght_of_pattern = 2; //длинна патерна
    int number_of_found_pattern = 0;

    unsigned char *work_pattern = new unsigned char[lenght_of_pattern];
    
    #define DEBUG_PRINT false
    #define DEBUG_PRINT_FIND_PUTTERN true
    
    for(int try_find=0;try_find<6;try_find++)
    {
        for(int offset_mass_ptr=0;offset_mass_ptr<mass_element-lenght_of_pattern;offset_mass_ptr++)
        {
            memcpy(work_pattern,mass+offset_mass_ptr,lenght_of_pattern);

            #if DEBUG_PRINT == 1
                printf(">>>>>> START find pattern ");
                printm(work_pattern,lenght_of_pattern);
            #endif

            for(int i=0;i<mass_element;i++)
            {
                if(!memcmp(mass+i,work_pattern,lenght_of_pattern))
                {
                    number_of_found_pattern++;

                    #if DEBUG_PRINT_FIND_PUTTERN == 1
                        //if(number_of_found_pattern-offset_mass_ptr>1)
                        {
                            printf("...find pattern ");
                            printm(work_pattern,lenght_of_pattern);
                            printf("position %d\n",i);
                        }
                    #endif

                }
            }
            
            number_of_found_pattern = 0;
        }

        delete work_pattern;
        lenght_of_pattern++; //нужна проверка длинны
        work_pattern = new unsigned char[lenght_of_pattern];
        //memcpy(work_pattern,mass,lenght_of_pattern);
    }

    //printf(">>>>>> pattern not found!\n");

   /*
    * 
    */
    
    std::cout << "<<<<<< END PROGRAMM >>>>>>" << std::endl;
}

