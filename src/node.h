#ifndef NODE_H
#define NODE_H

#include "namespace.h"
#include "exception.h"
#include <set>
#include <vector>
#include <string>

namespace EASYXML_NAMESPACE
{
	class Node
	{
	public:
		Node();
		Node(const char* name, const char* value = NULL);
		Node(const std::string& name, const std::string& value = "");
		Node(const Node& rhs);
		Node& operator=(const Node& rhs);

		std::string val() const;
		// Templated short-hand "getter" function
		template <class T> T val() const;

		Node* findNode(const std::string path, bool throwException = false) const;

		// Members should be public so they can be readable and writable by anyone
		std::string name;
		std::string value;

		std::vector<Node*> children; // for preserving order and duplicate xml nodes
		std::set<Node*, bool (*)(const Node*, const Node*)> sortedChildren; // for log(N) lookups

	private:
		// Comparator function used to sort the "children" set.
		static bool node_ptr_compare(const Node* lhs, const Node* rhs)
		{
			return lhs->name < rhs->name;
		}
	};
}

#endif
