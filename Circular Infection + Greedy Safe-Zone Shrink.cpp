/*
 *
 *  🔥 CIRCULAR INFECTION / SHRINKING SAFE ZONES (Greedy Pattern)

 *
 *  🧩 Problem Archetype:
 *   - You have N positions arranged in a circle (or line).
 *   - Some positions are "infected" or "broken".
 *   - Infection spreads 1 cell per side each day (2 total per day per cluster).
 *   - You can fix / defend / save exactly ONE cell per day.
 *   - Find how many cells can remain safe at the end.
 *
 *  ⚙️ Core Idea:
 *   1️⃣ Convert circular structure → "gaps" (safe zones) between infected points.
 *   2️⃣ Infection shrinks each gap by 2/day (1 from each side).
 *   3️⃣ You fix one/day → act greedily on largest gaps first.
 *   4️⃣ For each subsequent gap, infection has already spread 2*i units (i = index in sorted order).
 *   5️⃣ Survivors = Σ(max(0, gap - 2*i - 1))
 *
 *  🧠 WHY THIS WORKS:
 *   - While you fix large gaps first, infection simultaneously eats smaller ones.
 *   - The term `2*i` represents parallel infection that happened while you worked earlier.
 *   - Greedy is optimal since larger gaps offer more “time buffer” before they vanish.
 *
 *  💡 Typical Appearances:
 *   - Circular zombies / virus spread
 *   - Burning trees or cities on fire
 *   - Defending islands, lights, or gardens
 *   - "Each day you can save 1" → dead giveaway for this pattern
 *
 *  🧮 Complexity:
 *   - Time: O(N log N)   (for sorting gaps)
 *   - Space: O(N)
 */

#include <bits/stdc++.h>
using namespace std;

int maxSurvivors(vector<int>& lights) {
    int n = lights.size();

    // Step 1️⃣: Collect positions of broken / infected lights
    vector<int> broken;
    for (int i = 0; i < n; i++)
        if (lights[i] == 0)
            broken.push_back(i);

    // Edge case: if all are working, all survive
    if (broken.empty()) return n;

    int m = broken.size();
    vector<int> gaps;

    // Step 2️⃣: Compute gaps (safe segments) between infected points circularly
    for (int i = 0; i < m; i++) {
        int next = broken[(i + 1) % m];
        // ⚠️ Observation: Need modular difference for circular structure
        int gap = (next - broken[i] - 1 + n) % n;
        if (gap > 0)
            gaps.push_back(gap);
    }

    // Step 3️⃣: Sort gaps descending (largest safe zones first)
    sort(gaps.rbegin(), gaps.rend());

    int days = 0; // 2*i → infection already spread before current fix
    int saved = 0;

    // Step 4️⃣: Greedy simulation
    for (long long g : gaps) {
            long long rem = g - 2 * days; // how many uninfected remain in this gap after infection has advanced 2*days
            if (rem <= 0) continue;       // already overtaken, check next gap
            if (rem == 1) {
                // we can patch that single node this day
                saved += 1;
                days += 1;
            }
            else if (rem == 2) {
                days += 1;   // only one day passes
                saved += 1;  // patch one of the two -> save 1
            }else {
                // rem >= 2 -> we can save rem-1 nodes but it consumes 2 days of action
                saved += rem - 1;
                days += 2;
            }
        }

    return saved;
}

//very important observation:
/*Perfect — let’s dry-run that code section line by line on your exact example to confirm how it models the infection and fixing process.

🧩 Input setup

We have:

gaps = [5, 3];       // after sorting descending
infectedSpread = 0;
saved = 0;


We’ll iterate i = 0 → 1.

🔁 Iteration 1 (i = 0, first gap = 5)
int remaining = gaps[i] - infectedSpread;


➡ remaining = 5 - 0 = 5

if (remaining <= 0) break;


❌ Not triggered (since 5 > 0)

saved += max(0, remaining - 1);


➡ remaining - 1 = 5 - 1 = 4
➡ saved = 0 + 4 = 4

🧠 Meaning in words:

You started with a safe zone of 5 lights.

On the first day, infection hasn’t spread yet.

You can fix one light, but infection will eat 1 boundary cell by the next day.

So, effectively 4 safe lights survive.

infectedSpread += 2;


➡ infectedSpread = 0 + 2 = 2

🧠 Meaning in words:

One full day has passed.

Infection has now spread 2 cells outward total (1 per side) from all infected sources.

Any other gap we handle next will already have been eaten by those 2 cells.

🔁 Iteration 2 (i = 1, second gap = 3)
int remaining = gaps[i] - infectedSpread;


➡ remaining = 3 - 2 = 1

🧠 Meaning: The small gap (3 lights) has already lost 2 to infection spread before we even get here.

if (remaining <= 0) break;


❌ Not yet (1 > 0), so continue.

saved += max(0, remaining - 1);


➡ remaining - 1 = 1 - 1 = 0
➡ saved = 4 + 0 = 4

🧠 Meaning:
There’s only 1 light left in that gap, but infection eats 1 more at the next boundary step, so none are saved.
*/
// ------------------------------------------------------------
//  🧪 Example usage / Driver
// ------------------------------------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example input
    int n = 10;
    vector<int> lights = {1, 1, 0, 1, 1, 1, 0, 1, 1, 1};

    std::cout << "Maximum lights that can remain working: "
         << maxSurvivors(lights) << "\n";

    return 0;
}

/*
 * ------------------------------------------------------------
 *  📘 Deep Notes for Contest Thinking
 * ------------------------------------------------------------
 *  🧠 Thinking Path:
 *    - Circular + Spreading + One Action per Day
 *    → Convert to "gaps between infected".
 *    - Each gap shrinks symmetrically (2 per day total).
 *    - Greedy on largest gaps gives optimal survival.
 *
 *  🔍 Common Variations:
 *    - Linear form (remove modulo, compute simple differences)
 *    - Variable spread rate (replace 2*i by rate*i)
 *    - Multiple fixes/day (each fix reduces infection rate)
 *
 *  🎯 Recognition Cues:
 *    - "Each day X spreads to adjacent cells"
 *    - "You can save / fix one per day"
 *    - "Circular / row of N elements"
 *    - "Maximize survivors / minimize infection"
 *
 *  🚀 Codeforces Rating Range:
 *    ≈ 1600–1900 (Div 2 D / Div 3 E)
 *
 *  ✍️ Author Tip:
 *    Always draw the circle first.
 *    Mark infected points, measure the gaps, and reason in terms of days
 *    before infection overlaps — that’s the secret visualization.
 * ------------------------------------------------------------
 */
