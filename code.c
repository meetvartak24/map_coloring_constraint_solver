#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 20

/* Global variables */
int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

int vertices;
int edges;
int maxColors;

long long colorTrials = 0;
long long backtracks = 0;


/* Function declarations */
void initializeGraph(void);
void displayGraph(void);
bool isSafe(int vertex, int selectedColor);
bool graphColoring(int vertex);
void displaySolution(void);
void resetSolution(void);
void enterGraph(void);
void enterColors(void);
void solveMapColoring(void);
void displayStatistics(void);


/* Initialize graph */
void initializeGraph(void)
{
    int i, j;

    for (i = 0; i < MAX_VERTICES; i++)
    {
        for (j = 0; j < MAX_VERTICES; j++)
        {
            graph[i][j] = 0;
        }

        color[i] = 0;
    }

    colorTrials = 0;
    backtracks = 0;
}


/* Enter graph */
void enterGraph(void)
{
    int i;
    int source, destination;

    printf("\n========================================\n");
    printf("         ENTER GRAPH DETAILS\n");
    printf("========================================\n");

    do
    {
        printf("Enter number of vertices (1-%d): ", MAX_VERTICES);
        scanf("%d", &vertices);

        if (vertices < 1 || vertices > MAX_VERTICES)
        {
            printf("Invalid number of vertices.\n");
        }

    } while (vertices < 1 || vertices > MAX_VERTICES);

    initializeGraph();

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    if (edges < 0)
    {
        edges = 0;
    }

    printf("\nVertices are numbered from 1 to %d.\n", vertices);

    for (i = 0; i < edges; i++)
    {
        printf("\nEdge %d\n", i + 1);

        printf("Enter source vertex: ");
        scanf("%d", &source);

        printf("Enter destination vertex: ");
        scanf("%d", &destination);

        if (source < 1 || source > vertices ||
            destination < 1 || destination > vertices)
        {
            printf("Invalid vertex! Enter the edge again.\n");
            i--;
            continue;
        }

        if (source == destination)
        {
            printf("Self-loop is not allowed. Enter the edge again.\n");
            i--;
            continue;
        }

        /* Undirected graph */
        graph[source - 1][destination - 1] = 1;
        graph[destination - 1][source - 1] = 1;
    }

    printf("\nGraph successfully created.\n");
}


/* Display adjacency matrix */
void displayGraph(void)
{
    int i, j;

    if (vertices == 0)
    {
        printf("\nPlease create a graph first.\n");
        return;
    }

    printf("\n========================================\n");
    printf("          ADJACENCY MATRIX\n");
    printf("========================================\n\n");

    printf("    ");

    for (i = 0; i < vertices; i++)
    {
        printf("%3d", i + 1);
    }

    printf("\n");

    for (i = 0; i < vertices; i++)
    {
        printf("%3d ", i + 1);

        for (j = 0; j < vertices; j++)
        {
            printf("%3d", graph[i][j]);
        }

        printf("\n");
    }
}

/* Check whether a colour is safe */
bool isSafe(int vertex, int selectedColor)
{
    int i;

    for (i = 0; i < vertices; i++)
    {
        if (graph[vertex][i] == 1 &&
            color[i] == selectedColor)
        {
            return false;
        }
    }

    return true;
}


/* Recursive graph coloring */
bool graphColoring(int vertex)
{
    int selectedColor;

    /* Base case */
    if (vertex == vertices)
    {
        return true;
    }

    /* Try colours from 1 to M */
    for (selectedColor = 1;
         selectedColor <= maxColors;
         selectedColor++)
    {
        colorTrials++;

        /* Check if colour is safe */
        if (isSafe(vertex, selectedColor))
        {
            color[vertex] = selectedColor;

            /* Move to next vertex */
            if (graphColoring(vertex + 1))
            {
                return true;
            }

            /* Backtrack */
            color[vertex] = 0;
            backtracks++;
        }
    }

    return false;
}


/* Reset solution */
void resetSolution(void)
{
    int i;

    for (i = 0; i < vertices; i++)
    {
        color[i] = 0;
    }

    colorTrials = 0;
    backtracks = 0;
}


/* Enter number of colours */
void enterColors(void)
{
    do
    {
        printf("\nEnter maximum number of colours (M): ");
        scanf("%d", &maxColors);

        if (maxColors < 1)
        {
            printf("Number of colours must be at least 1.\n");
        }

    } while (maxColors < 1);
}

/* Display solution */
void displaySolution(void)
{
    int i;

    printf("\n========================================\n");
    printf("          COLOR ASSIGNMENT\n");
    printf("========================================\n");

    printf("\nVertex\tColour\n");
    printf("----------------\n");

    for (i = 0; i < vertices; i++)
    {
        printf("V%-6d C%d\n", i + 1, color[i]);
    }

    printf("\nColouring is VALID.\n");
    printf("No adjacent vertices have the same colour.\n");
}


/* Display statistics */
void displayStatistics(void)
{
    printf("\n========================================\n");
    printf("        BACKTRACKING STATISTICS\n");
    printf("========================================\n");

    printf("Number of vertices : %d\n", vertices);
    printf("Number of edges    : %d\n", edges);
    printf("Colours available  : %d\n", maxColors);
    printf("Colour trials      : %lld\n", colorTrials);
    printf("Backtracks         : %lld\n", backtracks);
}


/* Solve map coloring */
void solveMapColoring(void)
{
    bool result;

    if (vertices == 0)
    {
        printf("\nPlease create a graph first.\n");
        return;
    }

    enterColors();
    resetSolution();

    printf("\n========================================\n");
    printf("       STARTING BACKTRACKING\n");
    printf("========================================\n");

    result = graphColoring(0);

    if (result)
    {
        displaySolution();
    }
    else
    {
        printf("\n========================================\n");
        printf("             NO SOLUTION\n");
        printf("========================================\n");

        printf("\nThe graph cannot be coloured using ");
        printf("%d colour(s).\n", maxColors);

        printf("Therefore, %d colours are NOT sufficient.\n",
               maxColors);
    }

    displayStatistics();
}


/* Main function */
int main(void)
{
    int choice;

    vertices = 0;
    edges = 0;
    maxColors = 0;

    initializeGraph();

    do
    {
        printf("\n\n========================================\n");
        printf("       MAP COLORING CONSTRAINT SOLVER\n");
        printf("========================================\n");

        printf("1. Enter Graph\n");
        printf("2. Display Graph\n");
        printf("3. Solve Map Coloring\n");
        printf("4. Display Solution\n");
        printf("5. Display Statistics\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enterGraph();
                break;

            case 2:
                displayGraph();
                break;

            case 3:
                solveMapColoring();
                break;

            case 4:
                if (vertices == 0)
                {
                    printf("\nPlease create a graph first.\n");
                }
                else if (color[0] == 0)
                {
                    printf("\nPlease solve the map coloring problem first.\n");
                }
                else
                {
                    displaySolution();
                }
                break;

            case 5:
                if (vertices == 0)
                {
                    printf("\nPlease create a graph first.\n");
                }
                else
                {
                    displayStatistics();
                }
                break;

            case 6:
                printf("\nThank you for using Map Coloring Solver.\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}