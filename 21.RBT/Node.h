#pragma once

// ����� ������ ��Ÿ���� ������.
enum class Color
{
	Red,
	Black
};

class Node
{
public:
	Node(int data, Color color = Color::Red);
	~Node() = default;

	// ������ �ʵ�.
	int GetData() const { return data; }
	void SetData(int newData) { data = newData; }

	// ����.
	Color GetColor() const { return color; }
	void SetColor(Color newColor) { color = newColor; }
	const char* GetColorString() const;

	// �θ� ���.
	Node* GetParent() const { return parent; }
	void SetParent(Node* newParent) { parent = newParent; }

	// ���� �ڼ� ���.
	Node* GetLeft() const { return left; }
	void SetLeft(Node* newLeft) { left = newLeft; }

	// ������ �ڼ� ���.
	Node* GetRight() const { return right; }
	void SetRight(Node* newRight) { right = newRight; }

private:

	// ������ �ʵ�.
	int data = 0;

	// ����.
	Color color = Color::Red;

	// �θ� ���.
	Node* parent = nullptr;

	// ���� �ڼ� ���.
	Node* left = nullptr;

	// ������ �ڼ� ���.
	Node* right = nullptr;
};