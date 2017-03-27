/*
  A simple program that simulates 5 MM1 queues at an airport. The first queue
  feeds 3 other queues that work in parallel. These feed a final queue.
  Simulation runs until error below threshold and, at the end,
  a performance evaluation report is shown, and logs are generated
  for plotting and analysis.
*/

using namespace std;

#include <random>
#include "customer.h"
#include "mm1_queue.h"


std::random_device rd;

void pause()
{
 std::string sInputString;
 // Wait for input from stdin (the keyboard)
 cout << "Continue (y)?";
 std::cin >> sInputString;
}

//add extra line from MM1 Queue Objects for Part III?
//MYOBJECTNAME.autogenerate_new_arrivals(false); //Added

int main(int argc, char* argv[])
{
   int next = 0;
//   test_random_number_generator();

   for (int cur_lambda = 3; cur_lambda < 34; cur_lambda++)
   {
      
	   //TODO Create MM1_Queue objects to capture the airport senario.
	   MM1_Queue    Q1;
	   Q1.set_file_names("Q1_log.txt", "Q1_wait.txt", "Q1_service.txt");
	   Q1.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   Q1.set_mu(53);
	   Q1.initialize();
	   Q1.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    Q2;
	   Q2.set_file_names("Q2_log.txt", "Q2_wait.txt", "Q2_service.txt");
	   Q2.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   Q2.set_mu(20);
	   Q2.autogenerate_new_arrivals(false);
	   Q2.initialize();
	   Q2.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    Q3;
	   Q3.set_file_names("Q3_log.txt", "Q3_wait.txt", "Q3_service.txt");
	   Q3.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   Q3.set_mu(20);
	   Q3.autogenerate_new_arrivals(false);
	   Q3.initialize();
	   Q3.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    Q4;
	   Q4.set_file_names("Q4_log.txt", "Q4_wait.txt", "Q4_service.txt");
	   Q4.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   Q4.set_mu(20);
	   Q4.autogenerate_new_arrivals(false);
	   Q4.initialize();
	   Q4.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    Q5;
	   Q5.set_file_names("Q5_log.txt", "Q5_wait.txt", "Q5_service.txt");
	   Q5.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   Q5.set_mu(80);
	   Q5.initialize();
	   Q5.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

   for (; 
		//TODO: add is_within_error_range check
	   !Q1.is_within_error_range(0.002) ||
	   !Q2.is_within_error_range(0.002) ||
	   !Q3.is_within_error_range(0.002) ||
	   !Q4.is_within_error_range(0.002) ||
	   !Q5.is_within_error_range(0.002) 
       ;)
   {
	   Customer cust = Q1.process_next_event();     // =  TODO: process next event;
	   Customer cust2 = Q2.process_next_event();    // =  TODO: process next event;
	   Customer cust3 = Q3.process_next_event();    // =  TODO: process next event;
	   Customer cust4 = Q4.process_next_event();    // =  TODO: process next event;
	   Customer cust5 = Q5.process_next_event();    // =  TODO: process next event;
	   //TODO: one more process_next_event for the last object.


       if (cust.get_type() == Customer::COMPLETED())
       {
          switch(next)
          {
            case 0:
				//TODO add_external_arrival() for your security gates;
				Q2.add_external_arrival();
                 break;
            case 1:
				//TODO add_external_arrival() for your security gates;
				Q3.add_external_arrival();
                 break;
            case 2:
                //TODO add_external_arrival() for your security gates;
				Q4.add_external_arrival();
                 break;
          }
          next++;
          if (next%3==0) next = 0;
       }
       if (cust2.get_type() == Customer::COMPLETED() || cust3.get_type() == Customer::COMPLETED() || cust4.get_type() == Customer::COMPLETED())
       {
		   //TODO add_external_arrival(); on your final boarding MM1_Queue object
		   Q5.add_external_arrival();
       }
   }



   //TODO Output statistics airport senario.



   //**************************************************************************
   //MYOBJECTNAME.get_current_time()
   //MYOBJECTNAME.plot_results_output();

   Q1.output(); cout << "*********" << endl;
   Q2.output(); cout << "*********" << endl;
   Q3.output(); cout << "*********" << endl;
   Q4.output(); cout << "*********" << endl;
   Q5.output(); cout << "*********" << endl;

   }

   return(0);
}

