  int findParents(int a, vector<int> &parents) {
      while(parents[a] != -1)
          a = parents[a];

      // path compression
      if(parents[a] != -1)
          parents[a] = a;
      return a;
  }

  void unionParents(int a, int b, vector<int> &parents, vector<int> &ranks) {
      if(ranks[a] > ranks[b])
          parents[a] = b;
      else if(ranks[b] > ranks[a])
          parents[b] = a;
      else {
          parents[a] = b;
          ranks[a]++;
      }
  }

  void disjointSet(vector<vector<int>>& v) {
      vector<int> parents(1007, -1);
      vector<int> ranks(1007, 0);

      for(auto it : v) {
          int parA = findParents(it[0], parents);
          int parB = findParents(it[1], parents);
          if(parA != parB)
              unionParents(parA, parB, parents, ranks);
      }
  }
