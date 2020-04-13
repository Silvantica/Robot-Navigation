#include "RobotNavigation.h"
#include "util/file.h"
#include "util/string.h"
#include "Grid.h"
#include "Tree.h"

#include <iostream>
#include <stdexcept>
#include <memory>

#include "DFS.h"

Tree RobotNavigation::whichMethod(std::string method, std::vector<std::string>& lines) {
  Grid grid(lines);
  //Tree tree(grid);

  // Uninformed
  if (method == "DFS") { return DFS::search(grid); } 
  //else if (method == "BFS") {

  //  return tree;
  //// Informed
  //} else if (method == "GBFS") {

  //  return tree;
  //} else if (method == "AS") {

  //  return tree;
  //// Custom
  //} else if (method == "CUS1") {

  //  return tree;
  //} else if (method == "CUS2") {

  //  return tree;
  //} else {
  //  return tree;
  //} //throw std::runtime_error("Unknown Method: " + method); }
  return DFS::search(grid);
}

std::string RobotNavigation::runFromFile(std::string filepath, std::string method) {
  std::vector<std::string> lines = util::file::readCleanLines(filepath);
  return run(filepath, lines, method);
}

std::string RobotNavigation::run(std::string filename, std::vector<std::string> lines, std::string method) {
  std::cout << filename << std::endl;
  auto tree = whichMethod("DFS", lines);
  //Grid grid(lines);
  //Tree tree(grid);

  return tree.toString();
}
