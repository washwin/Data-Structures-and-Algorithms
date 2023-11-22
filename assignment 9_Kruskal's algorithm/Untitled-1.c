
#include <stdio.h>
#include <stdlib.h>

struct edge
{
  int u;
  int v;
  int w;
};

struct edge_list
{
  struct edge data[111111];
  int size;
};

struct vertex_list
{
  int vertex[19999];
  int size;
};

struct span_list
{
  struct vertex_list list[19999];
  int size;
};

struct edge_list elist;
struct span_list slist;

int search();
void print();
void mergesort();
void merge();

int main(int argc, char *argv[])
{
  FILE *in;
  in = fopen(argv[1], "r");

  int x, y, z, i = 0;
  elist.size = 0;
  while (fscanf(in, "%d %d %d", &x, &y, &z) != EOF)
  {
    elist.data[i].u = x;
    elist.data[i].v = y;
    elist.data[i].w = z;
    i++;
  }
  elist.size = i;

  mergesort(0, elist.size - 1);

  rewind(in);
  i = 0;
  slist.size = 0;
  while (fscanf(in, "%d %d %d", &x, &y, &z) != EOF)
  {
    if (search(x) == 210010060)
    {
      slist.list[i].vertex[0] = x;
      slist.list[i].size = 1;
      i++;
      slist.size++;
    }

    if (search(y) == 210010060)
    {
      slist.list[i].vertex[0] = y;
      slist.list[i].size = 1;
      i++;
      slist.size++;
    }
  }
  fclose(in);

  FILE *op;
  op = fopen("mst.txt", "w");

  for (i = 0; i < elist.size; i++)
  {
    x = search(elist.data[i].u);
    y = search(elist.data[i].v);

    if (slist.list[x].size >= slist.size)
    {
      break;
    }

    if (x != y)
    {
      for (int j = 0; j < slist.list[y].size; j++)
      {
        slist.list[x].vertex[slist.list[x].size] = slist.list[y].vertex[j];
        slist.list[x].size++;
      }
      slist.list[y].size = 0;
      fprintf(op, "%d %d %d\n", elist.data[i].u, elist.data[i].v, elist.data[i].w);
    }
  }
  fclose(op);
}

int search(int n)
{
  for (int i = 0; i < slist.size; i++)
  {
    for (int j = 0; j < slist.list[i].size; j++)
    {
      if (n == slist.list[i].vertex[j])
      {
        return i;
      }
    }
  }
  return 210010060;
}

void mergesort(int i, int j)
{
  int mid;
  if (i < j)
  {
    mid = (i + j) / 2;
    mergesort(i, mid);         // left recursion
    mergesort(mid + 1, j);     // right recursion
    merge(i, mid, mid + 1, j); // merging of two sorted sub-arrays
  }
}

void merge(int i1, int j1, int i2, int j2)
{
  struct edge_list templist; 
  int i, j, k;
  i = i1;
  j = i2;
  k = 0;
  while (i <= j1 && j <= j2)
  {
    if (elist.data[i].w < elist.data[j].w)
    {
      templist.data[k++] = elist.data[i++];
    }
    else
    {
      templist.data[k++] = elist.data[j++];
    }
  }
  while (i <= j1)
  {
    templist.data[k++] = elist.data[i++];
  }
  while (j <= j2)
  {
    templist.data[k++] = elist.data[j++];
  }

  for (i = i1, j = 0; i <= j2; i++, j++)
  {
    elist.data[i] = templist.data[j];
  }
}