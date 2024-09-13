# The Question
Do towny candidates influence the election on a national level?

## Dataset
2019 European election in italy (only local, no estero)

## Definitions
- a candidate belongs to a party
- circoscrizione > regione > provincia > comune
- all candidates belong to at least one circoscrizione
- a national candidate is a candidate which gets all the votes that expressed no preference in a certain circoscrizione
- a towny candidate is a candidate which gets proportionally an overwhelming amount of votes
in one (or maybe two, three we have to put the bar somewhere) comune with respect to the nationwide scale 

## Steps
### Dataset pre processing
[] get the dataset in csv
[] organize dataset for python parsing 
[] examine the dataset and clean it

### find towny candidates
[] set bar for towny candidates classification
[] adjust number of comuni for towny candidate 
[] consider big, small city effects

### examine elected candidates votes
[] where do succesful candidates get their votes 
(Does their birthplace have any correlation with origin of votes?)
[] how candidates get elected in their party in relation with the votes they got 
(where they voted directly or where they pushed up by their party?) 
(how are votes distributed in a party?)

### Quantify the effect of towny candidates
[] scope of the party
[] scope of the elections

## Conclusions
