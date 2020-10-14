#include <stdlib.h>
#include <string.h>

typedef struct
{
	int data[5000][2];  //{time,top person}
	int dataSize;
} TopVotedCandidate;

TopVotedCandidate* topVotedCandidateCreate(int* persons, int personsSize, int* times, int timesSize)
{
	TopVotedCandidate* res = (TopVotedCandidate*)malloc(sizeof(TopVotedCandidate));
	res->dataSize = 0;
	int vote = 0, count[personsSize + 1];
	memset(count, 0, sizeof(count));
	for (int i = 0; i < timesSize; ++i)
	{
		if (++count[persons[i]] >= vote)
		{
			vote = count[persons[i]];
			res->data[res->dataSize][0] = times[i];
			res->data[res->dataSize][1] = persons[i];
			++res->dataSize;
		}
	}
	return res;
}

int topVotedCandidateQ(TopVotedCandidate* obj, int t)
{
	int lo = 0, hi = obj->dataSize;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (obj->data[mi][0] <= t)
			lo = mi + 1;
		else
			hi = mi;
	}
	return obj->data[lo - 1][1];
}

void topVotedCandidateFree(TopVotedCandidate* obj)
{
	if (obj)
		free(obj);
}

/**
 * Your TopVotedCandidate struct will be instantiated and called as such:
 * TopVotedCandidate* obj = topVotedCandidateCreate(persons, personsSize, times, timesSize);
 * int param_1 = topVotedCandidateQ(obj, t);
 
 * topVotedCandidateFree(obj);
*/
