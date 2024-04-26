node *newNode = createNode(dest, weight);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;