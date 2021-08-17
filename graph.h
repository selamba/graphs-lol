//
// Created by selamba on 06/08/2021.
//

#pragma once

#include <array>
#include <concepts>
#include <functional>

template<typename VertexType = char>
struct Edge
{
	VertexType from;
	VertexType to;
	
	[[nodiscard]] constexpr bool is_self_loop() const noexcept
	{
		return this->from == this->to;
	}
	
	[[nodiscard]] constexpr bool is_proper_edge() const noexcept
	{
		return this->from != this->to;
	}
	
	[[nodiscard]] constexpr bool operator==(const Edge& other) const noexcept
	{
		return this->from == other.from && this->to == other.to;
	}
	
	template<typename Edge1, typename Edge2, typename... Edges>
	requires std::derived_from<Edge1, Edge> && std::derived_from<Edge2, Edge> && (std::derived_from<Edges, Edge> && ...)
	[[nodiscard]] static constexpr bool are_multi_edges(const Edge1& edge1, const Edge2& edge2, const Edges& ... edges) noexcept
	{
		// If only two edges were passed to the function, there's no need for any extra logic.
		if constexpr (sizeof...(edges) == 0)
			return edge1 == edge2;
		
		std::array<const decltype(std::cref(edge1)), sizeof...(edges) + 1> array {edge2, edges...};
		
		for (const Edge& edge : array)
			if (edge.from != edge1.from || edge.to != edge1.to)
				return false;
		
		return true;
	}
};