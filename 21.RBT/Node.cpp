#include "Node.h"

Node::Node(int data, Color color)
    : data(data), color(color)  // ∏‚πˆ ¿Ã¥œº»∂Û¿Ã¡Æ.
{
}

const char* Node::GetColorString() const
{
    return color == Color::Red ? "RED" : "BLACK";
}