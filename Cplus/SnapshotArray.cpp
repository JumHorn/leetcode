#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class SnapshotArray
{
public:
	SnapshotArray(int length) : data(length), snapid(0)
	{
		for (int i = 0; i < length; i++)
			data[i][0] = 0;
	}

	void set(int index, int val)
	{
		data[index][snapid] = val;
	}

	int snap()
	{
		return snapid++;
	}

	int get(int index, int snap_id)
	{
		if (data[index].find(snap_id) != data[index].end())
			return data[index][snap_id];
		auto iter = data[index].lower_bound(snap_id);
		--iter;
		return iter->second;
	}

private:
	vector<map<int, int>> data;
	int snapid;	 //0 based
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
