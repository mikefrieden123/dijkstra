#include "dijkstra.h"
#include <bits/stdc++.h> 
#include <utility>
#include <queue>

using namespace std;

class compareElem
{
  public:
    bool operator()(pair<int,float> n1,pair<int,float> n2) 
    {
      return n1.second>n2.second;
    }
};

string dijkstra(MyGraph *g, std::string q)
{
  string tempWord;
  int index = 0;
  for(int i = 31 ; i < q.length() ; i++)
  {
    tempWord += q[i];
    index++;
  }

  string firstCurrency;
    
  for(int j = 0 ; j < tempWord.length() ; j++)
  {
    if(tempWord[j] != ' ')
    {
      firstCurrency += tempWord[j];
    }
    else
    {
      break;
    }
  }

  string secondCurrency;
    
  for(int b = firstCurrency.length() + 4 ; b < tempWord.length() - 1 ; b++)
  {
    secondCurrency += tempWord[b];
  }
   
  string tempS1;
  for(int j = 0 ; j < firstCurrency.length() - 1 ; j++)
  {
    tempS1 += firstCurrency[j];
  }

  firstCurrency = tempS1;
    
  string tempS2;
  for(int j = 0 ; j < secondCurrency.length() - 1 ; j++)
  {
    tempS2 += secondCurrency[j];
  }
  secondCurrency = tempS2;

  int firstCurrIndex;
  int secondCurrIndex;
  for(int i = 0 ; i < g->vertListSize ; i++)
  {
    if(g->vertList[i].currencyName == firstCurrency)
    {
      firstCurrIndex = i;
      break;
    }
  }
  for(int i = 0 ; i < g->vertListSize ; i++)
  {
    if(g->vertList[i].currencyName == secondCurrency)
    {
      secondCurrIndex = i;
      break;
    }
  }

  bool *unvisited;
  int *pathArr;
  float *bribeArr;
  float *distance;
    
  int tempNeighbor;

  std::priority_queue<std::pair<int, float>, vector<std::pair<int, float>>, compareElem> vertexPq;
  std::pair<int, float> temp3(firstCurrIndex, 0);
  vertexPq.push(temp3);
            
  unvisited = new bool[g->vertListSize];
  
  for(int i = 0 ; i < g->vertListSize ; i++)
  {
    unvisited[i] = false;
  }
  
  int firstIndex;

  distance = new float[g->vertListSize];
  for(int i = 0 ; i < g->vertListSize ; i++)
  {
    if(i != firstCurrIndex)
    {
      distance[i] = INFINITY;
    }      
  }

  distance[firstCurrIndex] = 0;

  //distance = 0;  

  
  pathArr = new int[g->n_edges()];

  bribeArr = new float[g->vertListSize];
    
  for(int i = 0 ; i < g->vertListSize ; i++)
  {
    bribeArr[i] = 0;
  }

  std::pair<int, float> newTemp;
    
  for(int i = 0 ; i < g->vertListSize ; i++)
  {
    do
    {
      if(vertexPq.size() == 0)
      {
        if(unvisited[secondCurrIndex] == 1)
        {
          return "Found here, cout path later";
	}
	else
        {
          string output = "";
	  for(int i = 0 ; i < 4; i++)
          {
            output += g->vertList[pathArr[i]].currencyName;
            output += " ";
          }
          return "here";
        }
      }
      temp3.second = vertexPq.top().second;
      temp3.first = vertexPq.top().first;
      i = tempNeighbor;
      vertexPq.pop();
      i = firstCurrIndex;
        
    }while(unvisited[i] == true);
        
      unvisited[i] = true;

      if(distance[i] == INFINITY)
      {
        return "No Path"; //fix this
      } 
            
      for(tempNeighbor = g->get_first_neighbor(i) ; tempNeighbor < g->n_nodes() ; tempNeighbor = g->get_next_neighbor(i, tempNeighbor))
      {
        if(distance[i] + g->get_edge(i, tempNeighbor) < distance[tempNeighbor])
        {
	  distance[tempNeighbor] = distance[i] + g->get_edge(i, tempNeighbor);
	  newTemp.second = distance[tempNeighbor];
	  newTemp.first = tempNeighbor;

          pathArr[tempNeighbor] = i;
          bribeArr[tempNeighbor] = bribeArr[i] + g->vertList[i].weight;
          vertexPq.push(newTemp);
        }
        else if(distance[i] + g->get_edge(i, tempNeighbor) == distance[tempNeighbor])
        {
	  if(bribeArr[i] < bribeArr[newTemp.first])
          {
            distance[tempNeighbor] = distance[i] + g->get_edge(i, tempNeighbor);
            newTemp.second = distance[tempNeighbor];
            newTemp.first = tempNeighbor;

            pathArr[tempNeighbor] = i;
            bribeArr[newTemp.first] = g->vertList[i].weight;
	    i = tempNeighbor;
            vertexPq.push(newTemp);
	  }
	  else if(bribeArr[i] > bribeArr[newTemp.first])
          {
            distance[tempNeighbor] = distance[tempNeighbor];
	    newTemp.second = distance[tempNeighbor];
            newTemp.first = tempNeighbor;

            pathArr[tempNeighbor] = i;
            bribeArr[newTemp.first] = g->vertList[newTemp.first].weight;
            i = tempNeighbor;
            vertexPq.push(newTemp);
          }
        }
      }
  }

  return "here";
}
