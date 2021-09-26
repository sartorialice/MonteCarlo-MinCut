# MonteCarlo-MinCut
This program evaluates the probability of obtaining the Min Cut on the Fritsch graph by using a randomized Monte Carlo algorithm on $10^5$ run.

Implemented by Alice Sartori: https://github.com/sartorialice

## Description
To implement the randomized MinCut algorithm we use the 'MonteCarloMinCut()' funcion and four auxiliar functions to control the data structure.
This function executes the cut of a vertex until there are only two vertices left in the graph. First it samples a random edge and then gets the values of the corresponding vertices. Secondly we merge the second vertex of the edge with the first one, assigning it all the links of the second one.
At the end we delete the second vertex and all the links between this and the first one, after that we control if there are only four edges left, wich is the MinCut for the Fritsch graph.

## Values
The Min Cut obtained with this algorithm upon 10^5 are more or less 31000. Therefore the probability of getting the MinCut with this randomized Monte Carlo algorithm is 31%.
