#include "GBFS.h"

#include "../tree/PriorityQueueFrontier.h"
#include "../tree/Visited.h"
#include "../exceptions/NoPathFoundException.h"

Tree GBFS::search(Grid& grid) {
  PriorityQueueFrontier frontier;
  Visited visited;

  auto root = grid.getAgentNode();
  frontier.push(root, grid.manhattanDistanceToClosestGoal(root->getPosition()));
  visited.add(root);

  while (!frontier.empty()) {
    auto node = frontier.pop();

    if (node->getIsGoal()) {
      return Tree(root, node);
    }

    auto directions = { Direction::UP, Direction::LEFT, Direction::DOWN, Direction::RIGHT };
    for(auto direction : directions) {
      Node* child = visited.nullIfVisitedFromShorterPath(grid.getEmptyNode(node->getPosition().shift(direction)));
      if(child != nullptr) {
        node->addChild(direction, child);

        int priority = grid.manhattanDistanceToClosestGoal(child->getPosition());
        frontier.push(child, priority);
        visited.add(child);
      }
    }
  }

  throw NoPathFoundException();
}