from __future__ import annotations
from typing import Protocol, List, TypeVar, Optional
import collections

T = TypeVar('T')
Location = TypeVar('Location')

class graph(Protocol):
        def neighbor(self, id: Location) -> List[Location]:
            pass

class SimpleGraph(Graph):
    def __init__(self) -> None:
        self.edges: dict[Location, List[Location]] = {}
        
        def neighbor(self, id: Location) -> List[Location]:
            return self.edges.get(id, [])