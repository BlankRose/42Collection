/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   FT_Containers - btree_node.hpp                  */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Feb  7 15:05:44 CET 2023      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __BTREE_NODE_HPP__
# define __BTREE_NODE_HPP__

#include "tools.hpp"
namespace ft {

	enum BTree_Colors { RBT_RED, RBT_BLACK };

	struct BTree_RB {
		typedef BTree_RB *			base_pointer;
		typedef BTree_RB const *	const_base_pointer;

		BTree_Colors				_color;
		base_pointer				_parent;
		base_pointer				_left;
		base_pointer				_right;

		static base_pointer			min(base_pointer node)
			{ while (node->_left != nullptr) node = node->_left; return node; }
		static const_base_pointer	min(const_base_pointer node)
			{ while (node->_left != nullptr) node = node->_left; return node; }

		static base_pointer			max(base_pointer node)
			{ while (node->_right != nullptr) node = node->_right; return node; }
		static const_base_pointer	max(const_base_pointer node)
			{ while (node->_right != nullptr) node = node->_right; return node; }
	};

	template <typename T>
	struct BTree_Node : public BTree_RB
	{
		typedef BTree_Node<T> *		node_pointer;
		T							_value;
	};

	struct BTree_Handler
	{
		static BTree_RB *			BTree_Forward(BTree_RB * node)
		{
			if (node->_right != nullptr) {
				node = node->_right;
				while (node->_left != nullptr)
					node = node->_left;
			} else {
				BTree_RB *	alt = node->_parent;
				while (node == alt->_right) {
					node = alt;
					alt = alt->_parent;
				}
				if (node->_right != alt)
					node = alt;
			}
			return node;
		}

		static BTree_RB *			BTree_Backward(BTree_RB * node)
		{
			if (node->_color == RBT_RED && node->_parent->_parent == node)
				node = node->_right;
			else if (node->_left != nullptr) {
				BTree_RB *	alt = node->_left;
				while (alt->_right != nullptr)
					alt = alt->_right;
				node = alt;
			} else {
				BTree_RB *	alt = node->_parent;
				while (node == alt->_left) {
					node = alt;
					alt = alt->_parent;
				}
				node = alt;
			}
			return node;
		}

		static BTree_RB const *		BTree_Forward(BTree_RB const * node)
			{ return BTree_Forward(const_cast<BTree_RB *>(node)); }

		static BTree_RB const *		BTree_Backward(BTree_RB const * node)
			{ return BTree_Backward(const_cast<BTree_RB *>(node)); }

		static void			BTree_Rotate_Right(
			BTree_RB * const node, BTree_RB *&root)
		{
			BTree_RB * const alt = node->_left;
			node->_left = alt->_right;
			if (alt->_right != nullptr) 
				alt->_right->_parent = node;
			alt->_parent = node->_parent;

			if (node == root)
				root = alt;
			else if (node == node->_parent->_right)
				node->_parent->_right = alt;
			else
				node->_parent->_left = alt;
			alt->_right = node;
			node->_parent = alt;
		}

		static void			BTree_Rotate_Left(
			BTree_RB * const node, BTree_RB *&root)
		{
			BTree_RB * const alt = node->_right;

			node->_right = alt->_left;
			if (alt->_left != nullptr)
				alt->_left->_parent = node;
			alt->_parent = node->_parent;

			if (node == root)
				root = alt;
			else if (node == node->_parent->_left)
				node->_parent->_left = alt;
			else
				node->_parent->_right = alt;
			alt->_left = node;
			node->_parent = alt;
		}

		static void			BTree_Insert(
			bool const insert_left, BTree_RB * node, BTree_RB *parent, BTree_RB &header)
		{
			BTree_RB *&root = header._parent;

			node->_parent = parent;
			node->_left = nullptr;
			node->_right = nullptr;
			node->_color = RBT_RED;

			if (insert_left) {
				parent->_left = node;
				if (parent == &header) {
					header._parent = node;
					header._right = node;
				} else if (parent == header._left)
					header._left = node;
			} else {
				parent->_right = node;
				if (parent == header._right)
					header._right = node;
			}
			while (node != root && node->_parent->_color == RBT_RED) {
				BTree_RB * const	elder = node->_parent->_parent;

				if (node->_parent == elder->_left) {
					BTree_RB * const	alt = elder->_right;

					if (alt && alt->_color == RBT_RED) {
						node->_parent->_color = RBT_BLACK;
						alt->_color = RBT_BLACK;
						elder->_color = RBT_RED;
						node = elder;
					} else {
						if (node == node->_parent->_right) {
							node = node->_parent;
							BTree_Rotate_Left(node, root);
						}
						node->_parent->_color = RBT_BLACK;
						elder->_color = RBT_RED;
						BTree_Rotate_Right(elder, root);
					}
				} else {
					BTree_RB *const alt = elder->_left;

					if (alt && alt->_color == RBT_RED) {
						node->_parent->_color = RBT_BLACK;
						alt->_color = RBT_BLACK;
						elder->_color = RBT_RED;
						node = elder;
					} else {
						if (node == node->_parent->_left) {
							node = node->_parent;
							BTree_Rotate_Right(node, root);
						}
						node->_parent->_color = RBT_BLACK;
						elder->_color = RBT_RED;
						BTree_Rotate_Left(elder, root);
			}	}	}
			root->_color = RBT_BLACK;
		}

		static BTree_RB *	BTree_Erase(
			BTree_RB *const node, BTree_RB &header)
		{
			BTree_RB *&root = header._parent;
			BTree_RB *&leftmost = header._left;
			BTree_RB *&rightmost = header._right;
			BTree_RB *y = node;
			BTree_RB *x = nullptr;
			BTree_RB *x_parent = nullptr;

			if (y->_left == nullptr)
				x = y->_right;
			else if (y->_right == nullptr)
				x = y->_left;
			else {
				y = y->_right;
				while (y->_left != nullptr)
					y = y->_left;
				x = y->_right;
			}
			if (y != node) {
				node->_left->_parent = y;
				y->_left = node->_left;
				if (y != node->_right) {
					x_parent = y->_parent;
					if (x)
						x->_parent = y->_parent;
					y->_parent->_left = x;
					y->_right = node->_right;
					node->_right->_parent = y;
				} else {
					x_parent = y;
				}
				if (root == node)
					root = y;
				else if (node->_parent->_left == node)
					node->_parent->_left = y;
				else
					node->_parent->_right = y;
				y->_parent = node->_parent;
				std::swap(y->_color, node->_color);
				y = node;
			} else {
				x_parent = y->_parent;
				if (x)
					x->_parent = y->_parent;
				if (root == node) {
					root = x;
				} else if (node->_parent->_left == node) {
					node->_parent->_left = x;
				} else {
					node->_parent->_right = x;
				}
				if (leftmost == node) {
					if (node->_right == nullptr)
						leftmost = node->_parent;
					else
						leftmost = BTree_RB::min(x);
				}
				if (rightmost == node) {
					if (node->_left == nullptr)
						rightmost = node->_parent;
					else
						rightmost = BTree_RB::max(x);
			}	}
			if (y->_color != RBT_RED) {
				while (x != root && (x == nullptr || x->_color == RBT_BLACK)) {
					if (x == x_parent->_left) {
						BTree_RB *w = x_parent->_right;
						if (w->_color == RBT_RED) {
							w->_color = RBT_BLACK;
							x_parent->_color = RBT_RED;
							BTree_Rotate_Left(x_parent, root);
							w = x_parent->_right;
						}
						if ((w->_left == nullptr || w->_left->_color == RBT_BLACK)
							&& (w->_right == nullptr || w->_right->_color == RBT_BLACK)) {
							w->_color = RBT_RED;
							x = x_parent;
							x_parent = x_parent->_parent;
						} else {
							if (w->_right == nullptr || w->_right->_color == RBT_BLACK) {
								w->_left->_color = RBT_BLACK;
								w->_color = RBT_RED;
								BTree_Rotate_Right(w, root);
								w = x_parent->_right;
							}
							w->_color = x_parent->_color;
							x_parent->_color = RBT_BLACK;
						if (w->_right)
									w->_right->_color = RBT_BLACK;
							BTree_Rotate_Left(x_parent, root);
							break;
						}
					} else {
						BTree_RB *w = x_parent->_left;
						if (w->_color == RBT_RED) {
							w->_color = RBT_BLACK;
							x_parent->_color = RBT_RED;
							BTree_Rotate_Right(x_parent, root);
							w = x_parent->_left;
						}
						if ((w->_right == nullptr || w->_right->_color == RBT_BLACK)
							&& (w->_left == nullptr || w->_left->_color == RBT_BLACK)) {
							w->_color = RBT_RED;
							x = x_parent;
							x_parent = x_parent->_parent;
						} else {
							if (w->_left == nullptr || w->_left->_color == RBT_BLACK) {
								w->_right->_color = RBT_BLACK;
								w->_color = RBT_RED;
								BTree_Rotate_Left(w, root);
								w = x_parent->_left;
							}
							w->_color = x_parent->_color;
							x_parent->_color = RBT_BLACK;
							if (w->_left)
								w->_left->_color = RBT_BLACK;
							BTree_Rotate_Right(x_parent, root);
							break;
				}	}	}
				if (x)
					x->_color = RBT_BLACK;
			}
			return y;
		}
	};

}

#endif /* __BTREE_NODE_HPP__ */