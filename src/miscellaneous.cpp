// This file is part of GQCG-cpputil.
// 
// Copyright (C) 2017-2018  the GQCG developers
// 
// GQCG-cpputil is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// GQCG-cpputil is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with GQCG-cpputil.  If not, see <http://www.gnu.org/licenses/>.
#include "miscellaneous.hpp"



#include <chrono>
#include <iostream>



namespace cpputil {


/**
 *  Print the time a function takes to be executed
 *
 *  @param function         the function call to be made
 *  @param method_name      the name of function that is to be executed
 */
void printExecutionTime(const std::string& method_name, const std::function<void()>& function) {

    // High resolution clock example from (https://stackoverflow.com/a/12231232/7930415)
    auto start = std::chrono::high_resolution_clock::now();

    function();

    auto stop = std::chrono::high_resolution_clock::now();


    // Print the timings
    std::cout << method_name << " took "
              << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count()
              << " microseconds ("
              << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count()
              << " milliseconds) to complete." << std::endl;
}


}  // namespace cpputil
