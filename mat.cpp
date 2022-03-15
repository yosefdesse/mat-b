






#include "mat.hpp"
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std ;

// using namespace ariel ;

// string nospaces(string input) {
// 	std::erase(input, ' ');
// 	std::erase(input, '\t');
// 	std::erase(input, '\n');
// 	std::erase(input, '\r');
// 	return input;
// }



void ariel::building_rug(int start_row ,int end_row , int start_col ,int  end_col ,char Symbol , vector<vector<char>> &rug)
{

    int row_length = rug.size();
    int col_length = rug[0].size();
   
    for(int i=0; i<=row_length/2 && i<=col_length/2; i++ ){

        // fill the rug row with symbol at their place
        for(int j=start_row   ; j< end_col ; j++){
            rug[end_row][j]= Symbol;
            rug[start_row][j]= Symbol;
        }
        // fill the rug column with symbol at their place
        for(int j=start_col   ; j< end_row ; j++){
            rug[j][end_col-1]= Symbol;
            rug[j][start_col]= Symbol;
        }
        //updete input
        start_col+=2;
        start_row+=2;
        end_col-=2;
        end_row-=2;
    }
    // string mat;
    // for (int i = 0; i < row; i++)
    // {
    //     string temp(rug[i].begin(), rug[i].end());
    //     mat += temp + '\n';
    // }
    // return mat;
}



string ariel::mat(int col , int row , char Symbol_1 , char Symbol_2){
    vector<vector<char>> rug ;
    if(( col <= 0)||(row <=0)){
        throw invalid_argument(" your input should be greater than 0 ");
    }

    if(( Symbol_1 < '!') || (Symbol_2 < '!') ||(Symbol_1 > '~') ||(Symbol_2 > '~') ){
        throw invalid_argument("bad symbol choose from ASCII table");
    }

    if((col % 2 ==0)||(row % 2 ==0)){
        throw invalid_argument( "invaled input - should be odd");
    }
    
  
    for(int i =0 ; i< row ; i++){
        vector <char> vector_row;
        vector_row.reserve(col);

        for(int j=0 ; j<col ;j++){
            vector_row.push_back(Symbol_2);
            
        }
        rug.push_back(vector_row);
        
    }
   
    building_rug(0 , row-1 , 0 , col , Symbol_1 , rug );
    string mat;

    
    
    for (int i = 0; i < row; i++)
    {
        string temp(rug[i].begin(), rug[i].end());
        mat += temp + '\n';
    }
    return mat;

 



}



