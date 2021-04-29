#include <map>
using namespace std;

#ifndef _DISJOINT_
#define _DISJOINT_

template <typename T>
class disjoint {
	public:
		T get_root(T son) {
			if (!this->dvalue.count(son)) return son;
			if (this->dvalue[son]!=son) {
				T res = get_root(this->dvalue[son]); // for faster
				this->dvalue[son] = res;
				return res;
			} else return son;
		}
		void set(T son,T father) {
			this->dvalue[son]=father;
		}
		bool is_same(T a,T b) {
			T ra = get_root(a);
			if (ra==get_root(b)) {
				this->dvalue[b]=ra;
				return true;
			} else return false;
		}
		void unionn(T a,T b) {
			this->dvalue[b]=get_root(this->dvalue[a]);
		}
	private:
		map<T,T> dvalue;
};

#endif
