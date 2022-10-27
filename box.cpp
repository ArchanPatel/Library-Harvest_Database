// 
// PURPOSE: Demo code to help with completion of SYDE 121::Lab Assignment #8 Part2.
//          No particular optimizations applied. The code structure emphasizes simplicity.
//          The code constructs emphasize those covered in the course.
//
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <ctime>

#include "lab08_box.hpp"
#include "lab08_produce.hpp"

using namespace std;

// constants that define the files with produce names
const string FruitsAndVeggiesBox::WINTER_FILE = "winter.txt";
const string FruitsAndVeggiesBox::SPRING_FILE = "spring.txt";
const string FruitsAndVeggiesBox::SUMMER_FILE = "summer.txt";
const string FruitsAndVeggiesBox::FALL_FILE = "fall.txt";

// constants that define the generation parameters for produce attributes
const int FruitsAndVeggiesBox::MAX_WEIGHT = 100 /* in grams */, FruitsAndVeggiesBox::MAX_DAY = 31 /* not checking for Feb 31st */;
const int FruitsAndVeggiesBox::MAX_MONTH = 12, FruitsAndVeggiesBox::MAX_YEAR_DIFF = 2 /* 2019 and 2020 as valid */;
const int FruitsAndVeggiesBox::NEXT_YEAR = 2019;

FruitsAndVeggiesBox::FruitsAndVeggiesBox() : order_size(0) {}

FruitsAndVeggiesBox::FruitsAndVeggiesBox(int new_order_size) : 
	order_size(new_order_size) {}

void FruitsAndVeggiesBox::print() {
	// print each vector separately by invoking class-specific print()
	for (int index = 0; index < winter_produce.size(); index++)
		winter_produce[index].print();

	for (int index = 0; index < spring_produce.size(); index++)
		spring_produce[index].print();

	for (int index = 0; index < summer_produce.size(); index++)
		summer_produce[index].print();

	for (int index = 0; index < fall_produce.size(); index++)
		fall_produce[index].print();
}

int FruitsAndVeggiesBox::size() {
	int cur_size = 0;

	// TODO: complete method definition here
	for (int i = 0; i < winter_produce.size(); i++)
		cur_size++;
	for (int i = 0; i < spring_produce.size(); i++)
		cur_size++;
	for (int i = 0; i < summer_produce.size(); i++)
		cur_size++;
	for (int i = 0; i < fall_produce.size(); i++)
		cur_size++;
	// add the number of items already inserted
	
	return cur_size;
}

void FruitsAndVeggiesBox::empty_the_box() {
	// TODO: complete method definition here
	winter_produce.clear();
	summer_produce.clear();
	fall_produce.clear();
	spring_produce.clear();
}

void FruitsAndVeggiesBox::file_to_vector(vector<string>& return_vector, string file_name) {
	// TODO: complete method definition here
	
	// step0. initialize corresponding variables
	string cur_string; ifstream my_file;

	// step1. open the corresponding file	
	my_file.open(file_name.c_str());	

	// step2. load the values from the file
	if (!my_file.fail())
	{
		while (!my_file.eof())
		{
			getline(my_file, cur_string);
			return_vector.push_back(cur_string);
		}
	}	
		
		// step3. close the file
		my_file.close();
	}


void FruitsAndVeggiesBox::load_up_produce_names() {
	// load up the four files one at a time
	file_to_vector(winter_produce_names, WINTER_FILE);
	file_to_vector(spring_produce_names, SPRING_FILE);
	file_to_vector(summer_produce_names, SUMMER_FILE);
	file_to_vector(fall_produce_names, FALL_FILE);
	
	// uncomment the folowing to check what names were loaded
	//print_loaded_names();  
}

void FruitsAndVeggiesBox::print_loaded_names() {
	// TODO: complete method definition here
	cout << "<WINTER PRODUCE ITEMS>" << endl;
	for (int i = 0; i < winter_produce_names.size(); i++)
		cout << winter_produce_names[i] << endl;
	cout << "<SPRING PRODUCE ITEMS>" << endl;
	for (int i = 0; i < spring_produce_names.size(); i++)
		cout << spring_produce_names[i] << endl;
	cout << "<SUMMER PRODUCE ITEMS>" << endl;
	for (int i = 0; i < summer_produce_names.size(); i++)
		cout << summer_produce_names[i] << endl;
	cout << "<FALL PRODUCE ITEMS>" << endl;
	for (int i = 0; i < fall_produce_names.size(); i++)
		cout << fall_produce_names[i] << endl;
	// print each vector separately by listing each group of names separately
}

void FruitsAndVeggiesBox::assign_seasons(int current_month) {
	// remove previously set seasons
	produce_seasons.clear(); 
	// insert corresponding seasons based on specified rules
	switch (current_month) {
		case JAN:
			produce_seasons.push_back(WINTER);
			break;
		case FEB:
		case MAR:
			produce_seasons.push_back(WINTER);
			produce_seasons.push_back(SPRING);
			break;
		case APR:
			produce_seasons.push_back(SPRING);
			break;
		case MAY:
		case JUN:
			produce_seasons.push_back(SPRING);
			produce_seasons.push_back(SUMMER);
			break;
		case JUL:
			produce_seasons.push_back(SUMMER);
			break;
		case AUG:
		case SEP:
			produce_seasons.push_back(SUMMER);
			produce_seasons.push_back(FALL);
			break;
		case OCT:
			produce_seasons.push_back(FALL);
			break;
		case NOV:
		case DEC:
			produce_seasons.push_back(FALL);
			produce_seasons.push_back(WINTER);
			break;
	}
}

void FruitsAndVeggiesBox::generate_random_value(int vector_size) {
	// generate random values for the current produce item
	rand_item = rand() % vector_size; // random item name
	rand_weight = rand() % MAX_WEIGHT + 1; rand_day = rand() % MAX_DAY + 1;
	rand_month = rand() % MAX_MONTH + 1; rand_year = rand() % MAX_YEAR_DIFF + NEXT_YEAR;
}

void FruitsAndVeggiesBox::handle_winter_item() {
	// TODO: complete method definition here
	
	// step0. initialize corresponding variables
	bool unique = false;
	bool inserted = false;
	
	// step1. keep repeating this until a unique item is generated
	while (!inserted)
	{
		// step1.1. generate random values for the winter produce item
		generate_random_value(winter_produce_names.size());
		
		// step1.2. create a new WinterProduce instance with the matching values
		WinterProduce produce (winter_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);

		// step1.3. iterate through the winter produce vector to check if the item is unique
		for (int i = 0; i < winter_produce.size(); i++)
		{
			if (winter_produce[i] == produce)
				unique = true;
		}
		
		// step2. once a unique item is generated, store it into the vector
		if (!unique)
		{
			winter_produce.push_back(produce);
			inserted = true;
		}
	}		
}

void FruitsAndVeggiesBox::handle_spring_item() {
	// TODO: complete method definition here

	// step0. initialize corresponding variables
	bool unique = false;
	bool inserted = false;
	
	// step1. keep repeating this until a unique item is generated
	while (!inserted)
	{
		// step1.1. generate random values for the spring produce item
		generate_random_value(spring_produce_names.size());
		
		// step1.2. create a new SpringProduce instance with the matching values
		SpringProduce produce (spring_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);

		// step1.3. iterate through the spring produce vector to check if the item is unique
		for (int i = 0; i < spring_produce.size(); i++)
		{
			if (spring_produce[i] == produce)
				unique = true;
		}
		
		// step2. once a unique item is generated, store it into the vector
		if (!unique)
		{
			spring_produce.push_back(produce);
			inserted = true;
		}
	}
}

void FruitsAndVeggiesBox::handle_summer_item() {
	// TODO: complete method definition here
	
	// step0. initialize corresponding variables
	bool unique = false;
	bool inserted = false;
	
	// step1. keep repeating this until a unique item is generated
	while (!inserted)
	{
		// step1.1. generate random values for the summer produce item
		generate_random_value(summer_produce_names.size());
		
		// step1.2. create a new SummerProduce instance with the matching values
		SummerProduce produce (summer_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);

		// step1.3. iterate through the summer produce vector to check if the item is unique
		for (int i = 0; i < summer_produce.size(); i++)
		{
			if (summer_produce[i] == produce)
				unique = true;
		}
		
		// step2. once a unique item is generated, store it into the vector
		if (!unique)
		{
			summer_produce.push_back(produce);
			inserted = true;
		}
	}
}

void FruitsAndVeggiesBox::handle_fall_item() {
	// TODO: complete method definition here
	
	// step0. initialize corresponding variables
	bool unique = false;
	bool inserted = false;
	
	// step1. keep repeating this until a unique item is generated
	while (!inserted)
	{
		// step1.1. generate random values for the fall produce item
		generate_random_value(fall_produce_names.size());
		
		// step1.2. create a new FallProduce instance with the matching values
		FallProduce produce (fall_produce_names[rand_item], rand_weight, rand_day, rand_month, rand_year);

		// step1.3. iterate through the fall produce vector to check if the item is unique
		for (int i = 0; i < fall_produce.size(); i++)
		{
			if (fall_produce[i] == produce)
				unique = true;
		}
		
		// step2. once a unique item is generated, store it into the vector
		if (!unique)
		{
			fall_produce.push_back(produce);
			inserted = true;
		}
	}
}

void FruitsAndVeggiesBox::insert_unique_item() {
	// TODO: complete method definition here
	
	// step1. randomly generate a unique produce item
	// step1.1. randomly select a season from available seasons
	rand_season = rand() % produce_seasons.size();
	// step1.2. insert a new unique item with random values into the box
	switch (produce_seasons[rand_season]) {
		case WINTER:
			// step1.3a. insert winter produce item
			handle_winter_item();
			break;			
			
		case SPRING:
			// step1.3b. insert spring produce item
			handle_spring_item();
			break;
			
		case SUMMER:
			// step1.3c. insert summer produce item
			handle_summer_item();
			break;
			
		case FALL:
			// step1.3d. insert fall produce item
			handle_fall_item();
			break;
	}
}

void FruitsAndVeggiesBox::fill_the_box(int current_month) {
	// TODO: complete method definition here
	
	// step0. set the randomization seed
	srand (time(NULL));
	
	// step1. remove all items if some already inserted
	empty_the_box();
	
	// step2. load up produce names	
	load_up_produce_names();
	
	// step3. decide which seasons are current
	assign_seasons(current_month);

	// step4. insert matching unique items based on the current seasons
	while (FruitsAndVeggiesBox::size() < order_size)
        insert_unique_item();
}
