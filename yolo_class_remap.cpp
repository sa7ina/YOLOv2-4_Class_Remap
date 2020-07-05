#include <iostream>  
#include <string>
#include <fstream>
#include <vector>

//using namespace std; 

int main(int argc, char *argv[]) 
{ 
    std::string remap_file = "remap_table.txt";
    std::ifstream input(remap_file);
    std::string read_class[1000];
    std::string map_class[1000];
    int line_counter = 0;
    printf("class map:\n");
    for(std::string line; getline(input, line); )
    {
        read_class[line_counter] = line.substr(0, line.find(' '));
        map_class[line_counter] = line.substr(line.find(' ')+1, line.length());
        printf("in: %s | out: %s\n", read_class[line_counter].c_str(), map_class[line_counter].c_str());
        line_counter++;
    }
    input.close();

    std::string txt_list_file = "txt_list.tx";
    std::ifstream txt_list_input(txt_list_file);
    std::string txt_list_file_names[100000];
    std::string current_class_number;
    std::string new_class_number;
    std::string current_coordinates;
    std::string write_buf;
    line_counter = 0;
    printf("\nyolo files:");
    for(std::string line; getline(txt_list_input, line); )
    {
        txt_list_file_names[line_counter] = line;
        printf("\nin: %s\n", txt_list_file_names[line_counter].c_str());

        std::string current_file = txt_list_file_names[line_counter].c_str();
        std::ifstream current_input(current_file);

        
        auto pos = current_file.find_last_of ('/');
        std::string dir_only= current_file.substr (0, pos+1);
        std::string file_only= current_file.substr (pos+1, current_file.length());
        //printf("dir: %s\n", dir_only.c_str());
        //printf("file: %s\n", file_only.c_str());
        std::string current_file_out = dir_only + "0_out/" + file_only;
        printf("out: %s\n", current_file_out.c_str());
        std::ofstream outfile (current_file_out);
        
        for(std::string currrent_line; getline(current_input, currrent_line); )
        {
            current_class_number = currrent_line.substr(0, currrent_line.find(' '));
            current_coordinates = currrent_line.substr(currrent_line.find(' ')+1, currrent_line.length());
            printf("class: %s | coordinates: %s\n", current_class_number.c_str(), current_coordinates.c_str());
            
            for(int i = 0 ; i < 1000 ; i++)
            {
                
                if(read_class[i].compare(current_class_number) == 0)
                {
                    new_class_number = map_class[i];
                    printf("yes:%s,%s\n", read_class[i].c_str(), map_class[i].c_str());
                    break;
                }else{
                    new_class_number = current_class_number;
                    //printf("no:%s,%s\n", read_class[i].c_str(), map_class[i].c_str());
                }

            }
            write_buf = "";
            write_buf += new_class_number;
            write_buf += " ";
            write_buf += current_coordinates;
            printf("%s\n", write_buf.c_str());
            outfile << write_buf << std::endl;
        }
        outfile.close();
        current_input.close();
        line_counter++;
    }
    txt_list_input.close();

    return 0; 
} 
