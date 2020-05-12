#ifndef MYGRAPH_H
#define MYGRAPH_H

#include "graph.h"
#include <string>
#include <sstream>

class MyVertex
{
  public:
    string currencyName;
    float weight;
  public:
    MyVertex(){}
    MyVertex(const string &name, const float &wght): currencyName(name), weight(wght){}
};

class MyGraph: public Graph
{
  public:
    float** adjMatrix = nullptr;
    MyVertex* vertList = nullptr;
    int vertListSize = 0;
    int reservedSize = 0;

  //public:
    MyGraph()
    {
      adjMatrix = nullptr;
      vertList = nullptr;
      vertListSize = 0;
      reservedSize = 0;
    }
        
    ~MyGraph()
    {
      delete[] vertList;

      for(int i = 0 ; i < vertListSize ; i++)
      {
        delete[] adjMatrix[i];
        adjMatrix[i] = nullptr;
      }

      delete[] adjMatrix;
      adjMatrix = nullptr;
    }

    void reserveVertList(int newCap)
    {
      if(vertList == 0)
      {
        vertList = new MyVertex[newCap];
        reservedSize = newCap;
      }
      else
      {
        MyVertex * temp = new MyVertex[newCap];
        vertList = new MyVertex[newCap];
        for(int i = 0 ; i < newCap ; i++)
        {
          vertList[i] = temp[i];
        }

        delete[] temp;
        temp = nullptr;
        reservedSize = newCap;
      }
    }
        
    void fillMatrix()
    {
      int tempChar;
      string tempWord;
      string pastWord;
      int vertIndex = 0;
      int bribeIndex = 0;
      if(vertListSize == 0)
      {
        //reserveVertList(10);
        vertList = new MyVertex[10];
        reservedSize = 10;

      }

      string line;
      char tempChar2;
      string tempWord2;
      int rowIndex;
            
      string firstLine;
      cin.ignore(256, ',');
      getline(cin, firstLine);

      for(int i = 0 ; i < firstLine.length() ; i++)
      {
        tempChar = firstLine[i];
        if(((tempChar >= 'a' && tempChar <= 'z') || (tempChar >= 'A' && tempChar <= 'Z')) && tempChar != ' ')
        {
          tempWord += tempChar;
        }
        else if((pastWord != tempWord) && (tempChar != ' ') && (tempChar != '(') && (tempChar != '\0'))
        {
          vertList[vertIndex].currencyName = tempWord;
          vertIndex++;
          if(vertIndex > reservedSize * 0.7)
          {
            reserveVertList(vertIndex * 2);
          }
          if(tempWord == "")
          {
            vertIndex--;
          }
          pastWord = tempWord;
          tempWord = "";
        }
      }
      vertListSize = vertIndex;
      for(int j = 0 ; j < firstLine.length() ; j++)
      {
        tempChar = firstLine[j];
        if(((tempChar > '0' && tempChar < '9') || tempChar == '.'))
        {
          tempWord += tempChar;
        }
        else if(pastWord != tempWord && tempWord != "")
        {
          stringstream convert(tempWord);//convert from string to float
          float vertWght = 0;//^convert cont.
          convert>>vertWght;//^convert cont.
          vertList[bribeIndex].weight = vertWght;//fill vertList
          bribeIndex++;
          pastWord = tempWord;
          tempWord = "";
        }
      }      
      adjMatrix = new float*[vertListSize];

      for(int q = 0 ; q < vertListSize ; q++)
      {
        adjMatrix[q] = new float[vertListSize];
      }
            
      for(int b = 0 ; b < vertListSize ; b++)
      {
        cin.ignore(256, ','); 
        getline(cin, line);
        line += ',';
        rowIndex = 0;
                
        for(int r = 0 ; r < line.length() ; r++)
        {
          tempChar2 = line[r];
          if(tempChar2 != ',')
          {
            tempWord2 += tempChar2;
          }
          else
          {
            stringstream convert(tempWord2);//convert from string to float
            float edgeWght = 0;//^convert cont.
            convert>>edgeWght;//^convert cont.
            adjMatrix[b][rowIndex] = edgeWght; //fill matrix
            rowIndex++;
            tempWord2 = "";
          }
        }
      }
    }    

    int get_first_neighbor(int vert)
    {
      for(int i = 0 ; i < vertListSize ; i++)
      {
        if(adjMatrix[vert][i] != 0)
        {
          return i;
        }
      }
    }

    int get_next_neighbor(int vert, int prev_neigh)
    {
      for(int i = prev_neigh + 1 ; i < vertListSize ; i++)
      {
        if(adjMatrix[vert][i] != 0)
        {
          return i;
        }
      }            
      return vertListSize;
    }

    int n_nodes()
    {
      return vertListSize;
    }

    int n_edges()
    {
      int nodes = 0;
      for(int i = 0 ; i < vertListSize ; i++)
      {
        for(int j = 0 ; j < vertListSize ; j++)
        {
          if(adjMatrix[i][j] != 0)
          {
            nodes++;
          }
        }
      }
      return nodes;
    }

    void set_edge(int v1, int v2, float wght)
    {
      adjMatrix[v1][v2] = wght;
    }

    void del_edge(int v1, int v2)
    {
      adjMatrix[v1][v2] = 0;
    }

    float get_edge(int v1, int v2)
    {
      return adjMatrix[v1][v2];
    }

    void set_bribe(int v, float bribe)
    {
      vertList[v].weight = bribe;
    }

    float get_bribe(int v)
    {
      return vertList[v].weight;
    }

    void set_node_name(int v, string name)
    {
      vertList[v].currencyName = name;
    }

    string get_node_name(int v)
    {
      return vertList[v].currencyName;
    }

    string findQuestion()
    {
      string question;
      //cin.ignore(9999, '\n');
      getline(cin, question);
      char tempChar;
      string tempWord = "";

      for(int i = 0 ; i < question.length() ; i++)
      {
        tempChar = question[i];
        if(tempChar != ',')
        {
          tempWord += tempChar;
        }
      }
      return tempWord;
    }
        
};

#endif
