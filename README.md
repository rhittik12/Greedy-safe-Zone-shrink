Perfect 💥
Let’s build your pattern recognition toolkit — this is how top Codeforces/ICPC solvers classify problems mentally so they can spot the trick fast.

🎯 The Pattern Family:
“Infection / Defense / Shrinking Safe Zones on a Circular or Linear Structure”

This family appears under many disguises:

Zombies, viruses, or fires spreading

Trees or lamps dying

Guards, defenders, or fixes being placed

Circular or linear gardens, cities, islands

But they all share the same core mathematical pattern:

Some bad thing spreads 1 unit per side each day,
and you can protect/fix one element per day.
Find survivors or time to extinction.

🧩 Common Pattern Ingredients
Concept	Description	Keyword to Detect
Two states (safe / infected)	Binary array, or good/bad, or alive/dead	“spreads each day”
Spread per day by distance 1	Each infected affects its neighbors per time step	“adjacent”, “each day”, “radius grows”
You can act once per day	Fix, heal, defend, or block	“each day you can…”
Circular or linear structure	Either a line or a loop	“road”, “circle”, “ring”, “row”
Goal = maximize survivors or minimize damage	You’re racing against spread	“maximum alive”, “minimum infected”

Once you see these together — that’s your trigger 🧠💡
👉 Convert to “gaps shrinking from both sides” and use greedy.

🧠 Step Recognition Intuition
Step	Thought	Why
1️⃣	Represent infected positions	Infection sources
2️⃣	Measure gaps between infected ones	Each gap = safe segment
3️⃣	Infection shrinks each gap by 2/day	1 per side
4️⃣	Fix 1/day → prioritize large gaps	Greedy logic
5️⃣	Formula gap - 2*i → survivors	Account for spread delay
⚔️ Pattern Variations & Example Problems
Theme	Short Description	Contest Level	Notes
🧟 Zombie Infection on Circle	Given zombies and humans in a ring, humans die as infection spreads; you can save 1/day	CF Div 2 D (≈1700)	Exactly your current problem
🌲 Tree or Garden Protection	Trees planted in circle, some are burning; you water 1/day to stop spread	AtCoder D / CF D	Same gap logic
🏙️ City Defense	Cities on a line, enemies attack each day spreading left/right; you build 1 wall/day	CF 1600–1800	Gaps shrink symmetrically
🛡️ Virus vs Vaccine (1D)	Some positions infected, others healthy, one vaccine per day	LeetCode Hard	identical greedy
🔥 Circular Campfire Problem	Campfires burn in both directions; find how many safe trees remain	ICPC regional-type	Advanced version
⚔️ “Save the Prisoners” variant	People die linearly, you can rescue 1/day	CF D/E	Linear form (no circle)
🪜 How to Build the Intuition Fast

Visualize – draw the circle, mark infected points, and shade gaps.
Once you “see” gaps, you’ll never need to simulate daily spread.

Think shrinking – each day, each gap loses 2 in length.
That’s your “time” dimension compressed.

Greedy sense – bigger gaps give you time → always handle them first.

Translate to formula – (gap - 2*i)
→ represents infection that reached this segment while you were busy with earlier ones.

Stop when ≤ 0 – rest of the gaps are gone.

⚙️ Recognizing It in Contests

Look for problem statements that say:

“Each day … spreads to adjacent cells.”

“You can protect/fix one per day.”

“Find number of survivors / time until full infection.”

“Circle / ring / row of cities, lamps, or houses.”

→ 🚨 That’s the Gap + Greedy infection pattern.