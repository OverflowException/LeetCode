//If you are troubled by int overflow, just try long long int.
//When a int is forced to convert to a long long int, signal will not change.
//But after the conversion, operators will not overflow, will act in a normal way.


//current algo is just too slow

#include <cstdio>
#include <cstdlib>

#define MIN_INT (1 << (sizeof(int) * 8 - 1))
#define MAX_INT (MIN_INT - 1)
class Solution
{
 public: 
  int divide(int dividend, int divisor)
  {
    if(!(bool)divisor)
      return MAX_INT;

    bool sig_r = false;
    bool sig_1 = false;
    bool sig_2 = false;


    long long int ldividend = (long long int)dividend;
    long long int ldivisor = (long long int)divisor;
    if(sig_1 = (bool)(dividend & 0x80000000))
      ldividend = -(long long int)dividend;
    if(sig_2 = (bool)(divisor & 0x80000000))
      ldivisor = -(long long int)divisor;
    //Get the signal of result
    sig_r = sig_1 ^ sig_2;

    long long int prev_lresult = 0;
    long long int next_lresult = 1;
    long long int prev_lproduct = 0;
    long long int next_lproduct = ldivisor;
    //can be modified to O(log2n)
    while(next_lproduct <= ldividend)
      {
	//doubles each time
	prev_lresult = next_lresult;
	next_lresult += prev_lresult;

	prev_lproduct = next_lproduct;
	next_lproduct += prev_lproduct;
      }

    //This is when prev < ldivident && next > ldivident
    if(prev_lproduct < ldividend)
      {
	printf("prev = %lld  ", prev_lresult);
	while(true)
	  {
	    prev_lresult++;
	    prev_lproduct += ldivisor;

	    if(prev_lproduct > ldividend)
	      {
		prev_lresult--;
		break;
	      }
	    else if(prev_lproduct == ldividend)
	      break;
	  }
      }

    int result;
    //Negative
    if(sig_r)
      {
	//If smaller than the smallest int
	if(prev_lresult > (long long int)MAX_INT + 1)
	    prev_lresult = MAX_INT + 1;

	result = (int)(-prev_lresult);
      }
    //Positive
    else
      {
	//Larger than the largest int
	if(prev_lresult > (long long int)MAX_INT)
	  prev_lresult = MAX_INT;

	result = (int)prev_lresult;
      }

    return result;
  }    
};

int main(int argc, char** argv)
{
  printf("MAX = %d\n", MAX_INT);
  printf("MIN = %d\n", MIN_INT);

  Solution* s = new Solution;
  printf("MAX / MAX = %d\n", s->divide(MAX_INT, MAX_INT));
  printf("MAX / MIN = %d\n", s->divide(MAX_INT, MIN_INT));
  printf("MIN / MAX = %d\n", s->divide(MIN_INT, MAX_INT));
  printf("MIN / MIN = %d\n", s->divide(MIN_INT, MIN_INT));
  printf("MAX / 1 = %d\n", s->divide(MAX_INT, 1));
  printf("MAX / -1 = %d\n", s->divide(MAX_INT, -1));
  printf("MIN / 1 = %d\n", s->divide(MIN_INT, 1));
  printf("MIN / -1 = %d\n", s->divide(MIN_INT, -1));

  int max = MAX_INT;
  int min = MIN_INT;
  long long int testLong = min;
  testLong += 2;

  printf("testLong = %lld\n", testLong);
  printf("sizeof testLong = %d\n", sizeof(testLong));

  printf("result = %d\n", s->divide(atoi(argv[1]), atoi(argv[2])));
  return 0;
  //printf("%d", MIN_INT, -1);
}


