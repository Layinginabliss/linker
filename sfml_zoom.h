// include vector.h and sfml
// TODO:use macro

#include "vectors.h"
#include <SFML\Graphics.hpp>


#ifndef SFML_ZOOM_H
#define SFML_ZOOM_H

#define ZOOM_IN 1
#define ZOOM_OUT 2

void zoom_raw_size_value(float &value,v2f sensitivity,int action)
{
	if(action == 1) value = (value / sensitivity.x) * (sensitivity.x+sensitivity.y);
	if(action == 2) value = (value / sensitivity.x) * (sensitivity.x-sensitivity.y);

}
v2f zoom_raw_possition_value(v2f &value,v2f zoom_point,v2f sensitivity,int action)
{
	v2f zoom_d_pisce;
	v2f shape_position;

	shape_position = value;

	v2f distance = value - zoom_point;

	if(action == 1) zoom_d_pisce  =  v2f((distance / sensitivity.x) * (sensitivity.x+sensitivity.y));
	if(action == 2) zoom_d_pisce  =  v2f((distance / sensitivity.x) * (sensitivity.x-sensitivity.y));

	shape_position = v2f(zoom_d_pisce+zoom_point);

	value = shape_position;
	return shape_position;
}
void zoom_rectangle(sf::RectangleShape &rect,v2f zoom_point,v2f sensitivity,int action) // sensitiviy = (100,25) = 100/25 , 2/1, 5/3 or any
{
	v2f zoom_d_pisce;
	v2f shape_position;

	shape_position.set(rect.getPosition().x,
		               rect.getPosition().y);

	v2f distance = shape_position - zoom_point;

	if(action == 1) zoom_d_pisce  =  (distance / sensitivity.x) * (sensitivity.x+sensitivity.y);
	if(action == 2) zoom_d_pisce  =  (distance / sensitivity.x) * (sensitivity.x-sensitivity.y);

	shape_position = zoom_d_pisce+zoom_point;

	rect.setPosition(shape_position.x,shape_position.y);

	////

	v2f shape_size(rect.getSize().x,
		           rect.getSize().y);

	if(action == 1) shape_size = (shape_size / sensitivity.x) * (sensitivity.x+sensitivity.y);
	if(action == 2) shape_size = (shape_size / sensitivity.x) * (sensitivity.x-sensitivity.y);

	rect.setSize(sf::Vector2f(shape_size.x,shape_size.y));

}
void zoom_circle(sf::CircleShape &circle,v2f zoom_point,v2f sensitivity,int action)
{
	v2f zoom_d_pisce;
	v2f shape_position;

	shape_position.set(circle.getPosition().x,
		               circle.getPosition().y);

	v2f distance = shape_position - zoom_point;

	if(action == 1) zoom_d_pisce  =  (distance / sensitivity.x) * (sensitivity.x+sensitivity.y);
	if(action == 2) zoom_d_pisce  =  (distance / sensitivity.x) * (sensitivity.x-sensitivity.y);

	shape_position = zoom_d_pisce+zoom_point;

	circle.setPosition(shape_position.x,shape_position.y);

	float r = circle.getRadius();
		
	if(action == 1) r = (r / sensitivity.x) * (sensitivity.x+sensitivity.y);
	if(action == 2) r = (r / sensitivity.x) * (sensitivity.x-sensitivity.y);
		
	circle.setRadius(r);

}
void zoom_points(sf::Vertex *points,int count,v2f zoom_point,v2f sensitivity,int action)
{
	for (int i = 0; i < count; i++)
	{

	v2f zoom_d_pisce;
	v2f shape_position;

	shape_position.set(points[i].position.x,
		               points[i].position.y);

	v2f distance = shape_position - zoom_point;

	if(action == 1) zoom_d_pisce  =  (distance / sensitivity.x) * (sensitivity.x+sensitivity.y);
	if(action == 2) zoom_d_pisce  =  (distance / sensitivity.x) * (sensitivity.x-sensitivity.y);

	shape_position = zoom_d_pisce+zoom_point;

	points[i] = sf::Vector2f(shape_position.x,shape_position.y);
	
	}
}

#endif