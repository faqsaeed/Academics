-- Query 1: Find the name of the strongest creature (highest rank)
SELECT Name
FROM Creature
WHERE CreatureID = (
    SELECT TOP 1 CreatureID
    FROM Rank
    WHERE Level = (SELECT MAX(Level) FROM Rank)
);

-- Query 2: Get the most frequently used ingredient
SELECT Name
FROM Ingredient
WHERE IngredientID = (
    SELECT TOP 1 IngredientID 
    FROM Creature_Ingredient 
    GROUP BY IngredientID 
    ORDER BY COUNT(*) DESC
);

-- Query 3: Retrieve the creature that fought the most battles
SELECT Name
FROM Creature
WHERE CreatureID = (
    SELECT TOP 1 CreatureID
    FROM (
        SELECT Creature1ID AS CreatureID FROM Fight
        UNION ALL
        SELECT Creature2ID FROM Fight
    ) AS BattleCounts
    GROUP BY CreatureID
    ORDER BY COUNT(*) DESC
);

-- Query 4: Find creatures with only one power
SELECT Name
FROM Creature
WHERE CreatureID IN (
    SELECT CreatureID 
    FROM Creature_Power 
    GROUP BY CreatureID 
    HAVING COUNT(PowerID) = 1
);

-- Query 5: Retrieve creatures that have never lost a fight
-- A creature loses a fight if, in any fight, its ID appears as either Creature1ID or Creature2ID and is not equal to WinnerID.
SELECT Name
FROM Creature
WHERE CreatureID NOT IN (
    SELECT Creature1ID FROM Fight WHERE WinnerID IS NOT NULL AND WinnerID <> Creature1ID
    UNION
    SELECT Creature2ID FROM Fight WHERE WinnerID IS NOT NULL AND WinnerID <> Creature2ID
);

-- Query 6: Get the youngest sibling (highest CreatureID among siblings)
SELECT Name
FROM Creature
WHERE CreatureID = (
    SELECT MAX(CreatureID)
    FROM (
        SELECT Creature1ID AS CreatureID FROM FamilyRelation WHERE RelationType = 'Sibling'
        UNION
        SELECT Creature2ID AS CreatureID FROM FamilyRelation WHERE RelationType = 'Sibling'
    ) AS Siblings
);

-- Query 7: Find the creature with the most powers
SELECT Name
FROM Creature
WHERE CreatureID = (
    SELECT TOP 1 CreatureID 
    FROM Creature_Power 
    GROUP BY CreatureID 
    ORDER BY COUNT(PowerID) DESC
);

-- Query 8: Get creatures that fought at least twice
SELECT Name
FROM Creature
WHERE CreatureID IN (
    SELECT CreatureID
    FROM (
        SELECT Creature1ID AS CreatureID FROM Fight
        UNION ALL
        SELECT Creature2ID FROM Fight
    ) AS Fights
    GROUP BY CreatureID
    HAVING COUNT(*) >= 2
);

-- Query 9: Find creatures that died and had a rank
SELECT Name
FROM Creature
WHERE CreatureID IN (SELECT CreatureID FROM DeathLog)
  AND CreatureID IN (SELECT CreatureID FROM Rank);

-- Query 10: Find creatures that used ‘Chemical X’ in their creation
SELECT Name
FROM Creature
WHERE CreatureID IN (
    SELECT CreatureID 
    FROM Creature_Ingredient 
    WHERE IngredientID = (
        SELECT IngredientID 
        FROM Ingredient 
        WHERE Name = 'Chemical X'
    )
);

-- Query 11: Find the creature that has fought against the most different opponents
SELECT Name
FROM Creature
WHERE CreatureID = (
    SELECT TOP 1 CreatureID
    FROM (
        SELECT Creature1ID AS CreatureID, Creature2ID AS Opponent FROM Fight
        UNION ALL
        SELECT Creature2ID, Creature1ID FROM Fight
    ) AS Battles
    GROUP BY CreatureID
    ORDER BY COUNT(DISTINCT Opponent) DESC
);
