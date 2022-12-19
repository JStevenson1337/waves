#include "../include/header.h"

/*
 * Main - Entry point of the program
 * @argc: number of arguments
 * @argv: double pointer to an array of arguments
 */
int main(int argc, char** argv)
{
	/* Local variables */
    int i;
    int j;
    int n;
    int sum;
    int* a;
	/* If no args were passed in assign argv[2] to default JSON file*/
	if (argc == 1)
	{
        printf("");
        return 0;
    }
	if(argc == 2)
	{
		if(strcmp(argv[1], "-h") == 0)
		{
			printf("\nUsage: sunspot [FILE]\n");
			printf("A program to read sunspot data from a json file\n");
			printf("\nOptions:\n");
			printf("  -h\t\t\tDisplay this help menu.\n");
			printf("  FILE\t\t\tName of file to read sunspot data from.\n\n");
			return 0;
		}
		else
		{
			argv[2] = argv[1];
			argv[1] = "../In_Data.json";
		}
	}
}
/*
 * Sunspot constructor - Constructs a Sunspot object
 * @filename - Name of the file to read sunspot data from
 * @return - None
 */
DateConverter::Sunspot(const char *filename)
{
	// Set the filename
	this->filename = filename;

	// Read the data from the file
	this->readData();
}

/*
 * Sunspot destructor - Destructs a Sunspot object
 * @return - None
 */
DateConverter::~DateConverter()
{
	// Free the memory for the data
	free(this->data);
}

/*
 * readData - Reads data from the file and stores it in the data member
 * @return - None
 */
void DateConverter::readData()
{
	// Open the file
	FILE *fp = fopen(this->filename, "r");
	if (fp == NULL)
	{
		printf("Error: Could not open file '%s'\n", this->filename);
		exit(1);
	}

	// Read the data
	int num_entries = 0;
	ss_data *data = NULL;
	while (!feof(fp))
	{
		// Allocate memory for the new entry
		data = (ss_data*) realloc(data, (num_entries + 1) * sizeof(ss_data));
		if (data == NULL)
		{
			printf("Error: Could not allocate memory for data\n");
			exit(1);
		}

		// Read the data
		fscanf(fp, "%d %d %d %d", &(data[num_entries].year), &(data[num_entries].month),
			&(data[num_entries].day), &(data[num_entries].num_sunspots));

		// Increment the number of entries
		num_entries++;
	}

	DateConverter data;
	data.dateToJulian(num_entries[i]);


	/*
	 * getNumEntries - Returns the number of entries in the data
	 * @return - The number of entries in the data
	 */
	int Sunspot::getNumEntries()
	{
		return this->num_entries;
	}

	/*
	 * getData - Returns the data
	 * @return - The data
	 */
	ss_data* Sunspot::getData()
	{
		return this->data;
	}


















	/* Allocate memory for the array */
    a = (int*)malloc(n * sizeof(int));

    /* Read in the array elements */
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    /* Calculate the sum */
    sum = 0;
    for(j = 0; j < n; j++)
    {
        sum += a[j];
    }

    /* Print the sum */
    printf("Sum = %d\n", sum);

    /* Deallocate the array */
    free(a);

	/* Create Fourier transform */
	float* fourier_transform = create_fourier_transform<float>(sine_wave);

	/* Display sine osodial wave on ncurses */
	display_sine_osodial_wave_on_ncurses<float>(sine_wave);

	/* Display Fourier transform on wxwidgets */
	display_fourier_transform_on_wxwidgets<float>(fourier_transform);

	/* Free memory */
	delete[] sine_wave;
	delete[] fourier_transform;

	/* Return success */

	return 0;
}
