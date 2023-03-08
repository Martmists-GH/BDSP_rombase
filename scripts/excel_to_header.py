data = """
1	Pound	Normal	Physical	35	40	100%	I
2	Karate Chop*	Fighting	Physical	25	50	100%	I
3	Double Slap	Normal	Physical	10	15	85%	I
4	Comet Punch	Normal	Physical	15	18	85%	I
5	Mega Punch	Normal	Physical	20	80	85%	I
6	Pay Day	Normal	Physical	20	40	100%	I
7	Fire Punch	Fire	Physical	15	75	100%	I
8	Ice Punch	Ice	Physical	15	75	100%	I
9	Thunder Punch	Electric	Physical	15	75	100%	I
10	Scratch	Normal	Physical	35	40	100%	I
11	Vise Grip	Normal	Physical	30	55	100%	I
12	Guillotine	Normal	Physical	5	—	30%	I
13	Razor Wind	Normal	Special	10	80	100%*	I
14	Swords Dance	Normal	Status	20*	—	—	I
15	Cut	Normal	Physical	30	50	95%	I
16	Gust*	Flying	Special	35	40	100%	I
17	Wing Attack	Flying	Physical	35	60*	100%	I
18	Whirlwind	Normal	Status	20	—	—*	I
19	Fly	Flying	Physical	15	90*	95%	I
20	Bind	Normal	Physical	20	15	85%*	I
21	Slam	Normal	Physical	20	80	75%	I
22	Vine Whip	Grass	Physical	25*	45*	100%	I
23	Stomp	Normal	Physical	20	65	100%	I
24	Double Kick	Fighting	Physical	30	30	100%	I
25	Mega Kick	Normal	Physical	5	120	75%	I
26	Jump Kick	Fighting	Physical	10*	100*	95%	I
27	Rolling Kick	Fighting	Physical	15	60	85%	I
28	Sand Attack*	Ground	Status	15	—	100%	I
29	Headbutt	Normal	Physical	15	70	100%	I
30	Horn Attack	Normal	Physical	25	65	100%	I
31	Fury Attack	Normal	Physical	20	15	85%	I
32	Horn Drill	Normal	Physical	5	—	30%	I
33	Tackle	Normal	Physical	35	40*	100%*	I
34	Body Slam	Normal	Physical	15	85	100%	I
35	Wrap	Normal	Physical	20	15	90%*	I
36	Take Down	Normal	Physical	20	90	85%	I
37	Thrash	Normal	Physical	10*	120*	100%	I
38	Double-Edge	Normal	Physical	15	120*	100%	I
39	Tail Whip	Normal	Status	30	—	100%	I
40	Poison Sting	Poison	Physical	35	15	100%	I
41	Twineedle	Bug	Physical	20	25	100%	I
42	Pin Missile	Bug	Physical	20	25*	95%*	I
43	Leer	Normal	Status	30	—	100%	I
44	Bite*	Dark	Physical	25	60	100%	I
45	Growl	Normal	Status	40	—	100%	I
46	Roar	Normal	Status	20	—	—*	I
47	Sing	Normal	Status	15	—	55%	I
48	Supersonic	Normal	Status	20	—	55%	I
49	Sonic Boom	Normal	Special	20	—*	90%	I
50	Disable	Normal	Status	20	—	100%*	I
51	Acid	Poison	Special	30	40	100%	I
52	Ember	Fire	Special	25	40	100%	I
53	Flamethrower	Fire	Special	15	90*	100%	I
54	Mist	Ice	Status	30	—	—	I
55	Water Gun	Water	Special	25	40	100%	I
56	Hydro Pump	Water	Special	5	110*	80%	I
57	Surf	Water	Special	15	90*	100%	I
58	Ice Beam	Ice	Special	10	90*	100%	I
59	Blizzard	Ice	Special	5	110*	70%*	I
60	Psybeam	Psychic	Special	20	65	100%	I
61	Bubble Beam	Water	Special	20	65	100%	I
62	Aurora Beam	Ice	Special	20	65	100%	I
63	Hyper Beam	Normal	Special	5	150	90%	I
64	Peck	Flying	Physical	35	35	100%	I
65	Drill Peck	Flying	Physical	20	80	100%	I
66	Submission	Fighting	Physical	20*	80	80%	I
67	Low Kick	Fighting	Physical	20	—*	100%*	I
68	Counter	Fighting	Physical	20	—	100%	I
69	Seismic Toss	Fighting	Physical	20	—	100%	I
70	Strength	Normal	Physical	15	80	100%	I
71	Absorb	Grass	Special	25*	20*	100%	I
72	Mega Drain	Grass	Special	15*	40*	100%	I
73	Leech Seed	Grass	Status	10	—	90%	I
74	Growth	Normal	Status	20*	—	—	I
75	Razor Leaf	Grass	Physical	25	55	95%	I
76	Solar Beam	Grass	Special	10	120*	100%	I
77	Poison Powder	Poison	Status	35	—	75%	I
78	Stun Spore	Grass	Status	30	—	75%	I
79	Sleep Powder	Grass	Status	15	—	75%	I
80	Petal Dance	Grass	Special	10*	120*	100%	I
81	String Shot	Bug	Status	40	—	95%	I
82	Dragon Rage	Dragon	Special	10	—*	100%	I
83	Fire Spin	Fire	Special	15	35*	85%*	I
84	Thunder Shock	Electric	Special	30	40	100%	I
85	Thunderbolt	Electric	Special	15	90*	100%	I
86	Thunder Wave	Electric	Status	20	—	90%*	I
87	Thunder	Electric	Special	10	110*	70%	I
88	Rock Throw	Rock	Physical	15	50	90%*	I
89	Earthquake	Ground	Physical	10	100	100%	I
90	Fissure	Ground	Physical	5	—	30%	I
91	Dig	Ground	Physical	10	80*	100%	I
92	Toxic	Poison	Status	10	—	90%*	I
93	Confusion	Psychic	Special	25	50	100%	I
94	Psychic	Psychic	Special	10	90	100%	I
95	Hypnosis	Psychic	Status	20	—	60%*	I
96	Meditate	Psychic	Status	40	—	—	I
97	Agility	Psychic	Status	30	—	—	I
98	Quick Attack	Normal	Physical	30	40	100%	I
99	Rage	Normal	Physical	20	20	100%	I
100	Teleport	Psychic	Status	20	—	—	I
101	Night Shade	Ghost	Special	15	—	100%	I
102	Mimic	Normal	Status	10	—	—*	I
103	Screech	Normal	Status	40	—	85%	I
104	Double Team	Normal	Status	15	—	—	I
105	Recover	Normal	Status	5*	—	—	I
106	Harden	Normal	Status	30	—	—	I
107	Minimize	Normal	Status	10*	—	—	I
108	Smokescreen	Normal	Status	20	—	100%	I
109	Confuse Ray	Ghost	Status	10	—	100%	I
110	Withdraw	Water	Status	40	—	—	I
111	Defense Curl	Normal	Status	40	—	—	I
112	Barrier	Psychic	Status	20*	—	—	I
113	Light Screen	Psychic	Status	30	—	—	I
114	Haze	Ice	Status	30	—	—	I
115	Reflect	Psychic	Status	20	—	—	I
116	Focus Energy	Normal	Status	30	—	—	I
117	Bide	Normal	Physical	10	—	—*	I
118	Metronome	Normal	Status	10	—	—	I
119	Mirror Move	Flying	Status	20	—	—	I
120	Self-Destruct	Normal	Physical	5	200*	100%	I
121	Egg Bomb	Normal	Physical	10	100	75%	I
122	Lick	Ghost	Physical	30	30*	100%	I
123	Smog	Poison	Special	20	30*	70%	I
124	Sludge	Poison	Special	20	65	100%	I
125	Bone Club	Ground	Physical	20	65	85%	I
126	Fire Blast	Fire	Special	5	110*	85%	I
127	Waterfall	Water	Physical	15	80	100%	I
128	Clamp	Water	Physical	15*	35	85%*	I
129	Swift	Normal	Special	20	60	—	I
130	Skull Bash	Normal	Physical	10*	130*	100%	I
131	Spike Cannon	Normal	Physical	15	20	100%	I
132	Constrict	Normal	Physical	35	10	100%	I
133	Amnesia	Psychic	Status	20	—	—	I
134	Kinesis	Psychic	Status	15	—	80%	I
135	Soft-Boiled	Normal	Status	5*	—	—	I
136	High Jump Kick	Fighting	Physical	10*	130*	90%	I
137	Glare	Normal	Status	30	—	100%*	I
138	Dream Eater	Psychic	Special	15	100	100%	I
139	Poison Gas	Poison	Status	40	—	90%*	I
140	Barrage	Normal	Physical	20	15	85%	I
141	Leech Life	Bug	Physical	10*	80*	100%	I
142	Lovely Kiss	Normal	Status	10	—	75%	I
143	Sky Attack	Flying	Physical	5	140*	90%	I
144	Transform	Normal	Status	10	—	—	I
145	Bubble	Water	Special	30	40*	100%	I
146	Dizzy Punch	Normal	Physical	10	70	100%	I
147	Spore	Grass	Status	15	—	100%	I
148	Flash	Normal	Status	20	—	100%*	I
149	Psywave	Psychic	Special	15	—	100%*	I
150	Splash	Normal	Status	40	—	—	I
151	Acid Armor	Poison	Status	20*	—	—	I
152	Crabhammer	Water	Physical	10	100*	90%*	I
153	Explosion	Normal	Physical	5	250*	100%	I
154	Fury Swipes	Normal	Physical	15	18	80%	I
155	Bonemerang	Ground	Physical	10	50	90%	I
156	Rest	Psychic	Status	5*	—	—	I
157	Rock Slide	Rock	Physical	10	75	90%	I
158	Hyper Fang	Normal	Physical	15	80	90%	I
159	Sharpen	Normal	Status	30	—	—	I
160	Conversion	Normal	Status	30	—	—	I
161	Tri Attack	Normal	Special	10	80	100%	I
162	Super Fang	Normal	Physical	10	—	90%	I
163	Slash	Normal	Physical	20	70	100%	I
164	Substitute	Normal	Status	10	—	—	I
165	Struggle	Normal	Physical	1*	50	—*	I
166	Sketch	Normal	Status	1	—	—	II
167	Triple Kick	Fighting	Physical	10	10	90%	II
168	Thief	Dark	Physical	25*	60*	100%	II
169	Spider Web	Bug	Status	10	—	—	II
170	Mind Reader	Normal	Status	5	—	—*	II
171	Nightmare	Ghost	Status	15	—	100%	II
172	Flame Wheel	Fire	Physical	25	60	100%	II
173	Snore	Normal	Special	15	50*	100%	II
174	Curse*	Ghost	Status	10	—	—	II
175	Flail	Normal	Physical	15	—	100%	II
176	Conversion 2	Normal	Status	30	—	—	II
177	Aeroblast	Flying	Special	5	100	95%	II
178	Cotton Spore	Grass	Status	40	—	100%*	II
179	Reversal	Fighting	Physical	15	—	100%	II
180	Spite	Ghost	Status	10	—	100%	II
181	Powder Snow	Ice	Special	25	40	100%	II
182	Protect	Normal	Status	10	—	—	II
183	Mach Punch	Fighting	Physical	30	40	100%	II
184	Scary Face	Normal	Status	10	—	100%*	II
185	Feint Attack	Dark	Physical	20	60	—	II
186	Sweet Kiss*	Fairy	Status	10	—	75%	II
187	Belly Drum	Normal	Status	10	—	—	II
188	Sludge Bomb	Poison	Special	10	90	100%	II
189	Mud-Slap	Ground	Special	10	20	100%	II
190	Octazooka	Water	Special	10	65	85%	II
191	Spikes	Ground	Status	20	—	—	II
192	Zap Cannon	Electric	Special	5	120*	50%	II
193	Foresight	Normal	Status	40	—	—*	II
194	Destiny Bond	Ghost	Status	5	—	—	II
195	Perish Song	Normal	Status	5	—	—	II
196	Icy Wind	Ice	Special	15	55	95%	II
197	Detect	Fighting	Status	5	—	—	II
198	Bone Rush	Ground	Physical	10	25	90%*	II
199	Lock-On	Normal	Status	5	—	—*	II
200	Outrage	Dragon	Physical	10*	120*	100%	II
201	Sandstorm	Rock	Status	10	—	—	II
202	Giga Drain	Grass	Special	10*	75*	100%	II
203	Endure	Normal	Status	10	—	—	II
204	Charm*	Fairy	Status	20	—	100%	II
205	Rollout	Rock	Physical	20	30	90%	II
206	False Swipe	Normal	Physical	40	40	100%	II
207	Swagger	Normal	Status	15	—	85%*	II
208	Milk Drink	Normal	Status	5*	—	—	II
209	Spark	Electric	Physical	20	65	100%	II
210	Fury Cutter	Bug	Physical	20	40*	95%	II
211	Steel Wing	Steel	Physical	25	70	90%	II
212	Mean Look	Normal	Status	5	—	—	II
213	Attract	Normal	Status	15	—	100%	II
214	Sleep Talk	Normal	Status	10	—	—	II
215	Heal Bell	Normal	Status	5	—	—	II
216	Return	Normal	Physical	20	—	100%	II
217	Present	Normal	Physical	15	—	90%	II
218	Frustration	Normal	Physical	20	—	100%	II
219	Safeguard	Normal	Status	25	—	—	II
220	Pain Split	Normal	Status	20	—	—*	II
221	Sacred Fire	Fire	Physical	5	100	95%	II
222	Magnitude	Ground	Physical	30	—	100%	II
223	Dynamic Punch	Fighting	Physical	5	100	50%	II
224	Megahorn	Bug	Physical	10	120	85%	II
225	Dragon Breath	Dragon	Special	20	60	100%	II
226	Baton Pass	Normal	Status	40	—	—	II
227	Encore	Normal	Status	5	—	100%	II
228	Pursuit	Dark	Physical	20	40	100%	II
229	Rapid Spin	Normal	Physical	40	50*	100%	II
230	Sweet Scent	Normal	Status	20	—	100%	II
231	Iron Tail	Steel	Physical	15	100	75%	II
232	Metal Claw	Steel	Physical	35	50	95%	II
233	Vital Throw	Fighting	Physical	10	70	—	II
234	Morning Sun	Normal	Status	5	—	—	II
235	Synthesis	Grass	Status	5	—	—	II
236	Moonlight*	Fairy	Status	5	—	—	II
237	Hidden Power	Normal	Special	15	60*	100%	II
238	Cross Chop	Fighting	Physical	5	100	80%	II
239	Twister	Dragon	Special	20	40	100%	II
240	Rain Dance	Water	Status	5	—	—	II
241	Sunny Day	Fire	Status	5	—	—	II
242	Crunch	Dark	Physical	15	80	100%	II
243	Mirror Coat	Psychic	Special	20	—	100%	II
244	Psych Up	Normal	Status	10	—	—	II
245	Extreme Speed	Normal	Physical	5	80	100%	II
246	Ancient Power	Rock	Special	5	60	100%	II
247	Shadow Ball	Ghost	Special	15	80	100%	II
248	Future Sight	Psychic	Special	10*	120*	100%*	II
249	Rock Smash	Fighting	Physical	15	40*	100%	II
250	Whirlpool	Water	Special	15	35*	85%*	II
251	Beat Up	Dark	Physical	10	—*	100%	II
252	Fake Out	Normal	Physical	10	40	100%	III
253	Uproar	Normal	Special	10	90*	100%	III
254	Stockpile	Normal	Status	20*	—	—	III
255	Spit Up	Normal	Special	10	—	100%	III
256	Swallow	Normal	Status	10	—	—	III
257	Heat Wave	Fire	Special	10	95*	90%	III
258	Hail	Ice	Status	10	—	—	III
259	Torment	Dark	Status	15	—	100%	III
260	Flatter	Dark	Status	15	—	100%	III
261	Will-O-Wisp	Fire	Status	15	—	85%*	III
262	Memento	Dark	Status	10	—	100%	III
263	Facade	Normal	Physical	20	70	100%	III
264	Focus Punch	Fighting	Physical	20	150	100%	III
265	Smelling Salts	Normal	Physical	10	70*	100%	III
266	Follow Me	Normal	Status	20	—	—	III
267	Nature Power	Normal	Status	20	—	—	III
268	Charge	Electric	Status	20	—	—	III
269	Taunt	Dark	Status	20	—	100%	III
270	Helping Hand	Normal	Status	20	—	—	III
271	Trick	Psychic	Status	10	—	100%	III
272	Role Play	Psychic	Status	10	—	—	III
273	Wish	Normal	Status	10	—	—	III
274	Assist	Normal	Status	20	—	—	III
275	Ingrain	Grass	Status	20	—	—	III
276	Superpower	Fighting	Physical	5	120	100%	III
277	Magic Coat	Psychic	Status	15	—	—	III
278	Recycle	Normal	Status	10	—	—	III
279	Revenge	Fighting	Physical	10	60	100%	III
280	Brick Break	Fighting	Physical	15	75	100%	III
281	Yawn	Normal	Status	10	—	—	III
282	Knock Off	Dark	Physical	20	65*	100%	III
283	Endeavor	Normal	Physical	5	—	100%	III
284	Eruption	Fire	Special	5	150	100%	III
285	Skill Swap	Psychic	Status	10	—	—	III
286	Imprison	Psychic	Status	10	—	—	III
287	Refresh	Normal	Status	20	—	—	III
288	Grudge	Ghost	Status	5	—	—	III
289	Snatch	Dark	Status	10	—	—	III
290	Secret Power	Normal	Physical	20	70	100%	III
291	Dive	Water	Physical	10	80*	100%	III
292	Arm Thrust	Fighting	Physical	20	15	100%	III
293	Camouflage	Normal	Status	20	—	—	III
294	Tail Glow	Bug	Status	20	—	—	III
295	Luster Purge	Psychic	Special	5	70	100%	III
296	Mist Ball	Psychic	Special	5	70	100%	III
297	Feather Dance	Flying	Status	15	—	100%	III
298	Teeter Dance	Normal	Status	20	—	100%	III
299	Blaze Kick	Fire	Physical	10	85	90%	III
300	Mud Sport	Ground	Status	15	—	—	III
301	Ice Ball	Ice	Physical	20	30	90%	III
302	Needle Arm	Grass	Physical	15	60	100%	III
303	Slack Off	Normal	Status	5*	—	—	III
304	Hyper Voice	Normal	Special	10	90	100%	III
305	Poison Fang	Poison	Physical	15	50	100%	III
306	Crush Claw	Normal	Physical	10	75	95%	III
307	Blast Burn	Fire	Special	5	150	90%	III
308	Hydro Cannon	Water	Special	5	150	90%	III
309	Meteor Mash	Steel	Physical	10	90*	90%*	III
310	Astonish	Ghost	Physical	15	30	100%	III
311	Weather Ball	Normal	Special	10	50	100%	III
312	Aromatherapy	Grass	Status	5	—	—	III
313	Fake Tears	Dark	Status	20	—	100%	III
314	Air Cutter	Flying	Special	25	60*	95%	III
315	Overheat	Fire	Special	5	130*	90%	III
316	Odor Sleuth	Normal	Status	40	—	—*	III
317	Rock Tomb	Rock	Physical	15*	60*	95%*	III
318	Silver Wind	Bug	Special	5	60	100%	III
319	Metal Sound	Steel	Status	40	—	85%	III
320	Grass Whistle	Grass	Status	15	—	55%	III
321	Tickle	Normal	Status	20	—	100%	III
322	Cosmic Power	Psychic	Status	20	—	—	III
323	Water Spout	Water	Special	5	150	100%	III
324	Signal Beam	Bug	Special	15	75	100%	III
325	Shadow Punch	Ghost	Physical	20	60	—	III
326	Extrasensory	Psychic	Special	20*	80	100%	III
327	Sky Uppercut	Fighting	Physical	15	85	90%	III
328	Sand Tomb	Ground	Physical	15	35*	85%*	III
329	Sheer Cold	Ice	Special	5	—	30%	III
330	Muddy Water	Water	Special	10	90*	85%	III
331	Bullet Seed	Grass	Physical	30	25*	100%	III
332	Aerial Ace	Flying	Physical	20	60	—	III
333	Icicle Spear	Ice	Physical	30	25*	100%	III
334	Iron Defense	Steel	Status	15	—	—	III
335	Block	Normal	Status	5	—	—	III
336	Howl	Normal	Status	40	—	—	III
337	Dragon Claw	Dragon	Physical	15	80	100%	III
338	Frenzy Plant	Grass	Special	5	150	90%	III
339	Bulk Up	Fighting	Status	20	—	—	III
340	Bounce	Flying	Physical	5	85	85%	III
341	Mud Shot	Ground	Special	15	55	95%	III
342	Poison Tail	Poison	Physical	25	50	100%	III
343	Covet	Normal	Physical	25*	60*	100%	III
344	Volt Tackle	Electric	Physical	15	120	100%	III
345	Magical Leaf	Grass	Special	20	60	—	III
346	Water Sport	Water	Status	15	—	—	III
347	Calm Mind	Psychic	Status	20	—	—	III
348	Leaf Blade	Grass	Physical	15	90*	100%	III
349	Dragon Dance	Dragon	Status	20	—	—	III
350	Rock Blast	Rock	Physical	10	25	90%*	III
351	Shock Wave	Electric	Special	20	60	—	III
352	Water Pulse	Water	Special	20	60	100%	III
353	Doom Desire	Steel	Special	5	140*	100%*	III
354	Psycho Boost	Psychic	Special	5	140	90%	III
355	Roost	Flying	Status	5*	—	—	IV
356	Gravity	Psychic	Status	5	—	—	IV
357	Miracle Eye	Psychic	Status	40	—	—	IV
358	Wake-Up Slap	Fighting	Physical	10	70*	100%	IV
359	Hammer Arm	Fighting	Physical	10	100	90%	IV
360	Gyro Ball	Steel	Physical	5	—	100%	IV
361	Healing Wish	Psychic	Status	10	—	—	IV
362	Brine	Water	Special	10	65	100%	IV
363	Natural Gift	Normal	Physical	15	—	100%	IV
364	Feint	Normal	Physical	10	30*	100%	IV
365	Pluck	Flying	Physical	20	60	100%	IV
366	Tailwind	Flying	Status	15*	—	—	IV
367	Acupressure	Normal	Status	30	—	—	IV
368	Metal Burst	Steel	Physical	10	—	100%	IV
369	U-turn	Bug	Physical	20	70	100%	IV
370	Close Combat	Fighting	Physical	5	120	100%	IV
371	Payback	Dark	Physical	10	50	100%	IV
372	Assurance	Dark	Physical	10	60*	100%	IV
373	Embargo	Dark	Status	15	—	100%	IV
374	Fling	Dark	Physical	10	—	100%	IV
375	Psycho Shift	Psychic	Status	10	—	100%*	IV
376	Trump Card	Normal	Special	5	—	—	IV
377	Heal Block	Psychic	Status	15	—	100%	IV
378	Wring Out	Normal	Special	5	—	100%	IV
379	Power Trick	Psychic	Status	10	—	—	IV
380	Gastro Acid	Poison	Status	10	—	100%	IV
381	Lucky Chant	Normal	Status	30	—	—	IV
382	Me First	Normal	Status	20	—	—	IV
383	Copycat	Normal	Status	20	—	—	IV
384	Power Swap	Psychic	Status	10	—	—	IV
385	Guard Swap	Psychic	Status	10	—	—	IV
386	Punishment	Dark	Physical	5	—	100%	IV
387	Last Resort	Normal	Physical	5	140*	100%	IV
388	Worry Seed	Grass	Status	10	—	100%	IV
389	Sucker Punch	Dark	Physical	5	70*	100%	IV
390	Toxic Spikes	Poison	Status	20	—	—	IV
391	Heart Swap	Psychic	Status	10	—	—	IV
392	Aqua Ring	Water	Status	20	—	—	IV
393	Magnet Rise	Electric	Status	10	—	—	IV
394	Flare Blitz	Fire	Physical	15	120	100%	IV
395	Force Palm	Fighting	Physical	10	60	100%	IV
396	Aura Sphere	Fighting	Special	20	80*	—	IV
397	Rock Polish	Rock	Status	20	—	—	IV
398	Poison Jab	Poison	Physical	20	80	100%	IV
399	Dark Pulse	Dark	Special	15	80	100%	IV
400	Night Slash	Dark	Physical	15	70	100%	IV
401	Aqua Tail	Water	Physical	10	90	90%	IV
402	Seed Bomb	Grass	Physical	15	80	100%	IV
403	Air Slash	Flying	Special	15*	75	95%	IV
404	X-Scissor	Bug	Physical	15	80	100%	IV
405	Bug Buzz	Bug	Special	10	90	100%	IV
406	Dragon Pulse	Dragon	Special	10	85*	100%	IV
407	Dragon Rush	Dragon	Physical	10	100	75%	IV
408	Power Gem	Rock	Special	20	80*	100%	IV
409	Drain Punch	Fighting	Physical	10*	75*	100%	IV
410	Vacuum Wave	Fighting	Special	30	40	100%	IV
411	Focus Blast	Fighting	Special	5	120	70%	IV
412	Energy Ball	Grass	Special	10	90*	100%	IV
413	Brave Bird	Flying	Physical	15	120	100%	IV
414	Earth Power	Ground	Special	10	90	100%	IV
415	Switcheroo	Dark	Status	10	—	100%	IV
416	Giga Impact	Normal	Physical	5	150	90%	IV
417	Nasty Plot	Dark	Status	20	—	—	IV
418	Bullet Punch	Steel	Physical	30	40	100%	IV
419	Avalanche	Ice	Physical	10	60	100%	IV
420	Ice Shard	Ice	Physical	30	40	100%	IV
421	Shadow Claw	Ghost	Physical	15	70	100%	IV
422	Thunder Fang	Electric	Physical	15	65	95%	IV
423	Ice Fang	Ice	Physical	15	65	95%	IV
424	Fire Fang	Fire	Physical	15	65	95%	IV
425	Shadow Sneak	Ghost	Physical	30	40	100%	IV
426	Mud Bomb	Ground	Special	10	65	85%	IV
427	Psycho Cut	Psychic	Physical	20	70	100%	IV
428	Zen Headbutt	Psychic	Physical	15	80	90%	IV
429	Mirror Shot	Steel	Special	10	65	85%	IV
430	Flash Cannon	Steel	Special	10	80	100%	IV
431	Rock Climb	Normal	Physical	20	90	85%	IV
432	Defog	Flying	Status	15	—	—	IV
433	Trick Room	Psychic	Status	5	—	—	IV
434	Draco Meteor	Dragon	Special	5	130*	90%	IV
435	Discharge	Electric	Special	15	80	100%	IV
436	Lava Plume	Fire	Special	15	80	100%	IV
437	Leaf Storm	Grass	Special	5	130*	90%	IV
438	Power Whip	Grass	Physical	10	120	85%	IV
439	Rock Wrecker	Rock	Physical	5	150	90%	IV
440	Cross Poison	Poison	Physical	20	70	100%	IV
441	Gunk Shot	Poison	Physical	5	120	80%*	IV
442	Iron Head	Steel	Physical	15	80	100%	IV
443	Magnet Bomb	Steel	Physical	20	60	—	IV
444	Stone Edge	Rock	Physical	5	100	80%	IV
445	Captivate	Normal	Status	20	—	100%	IV
446	Stealth Rock	Rock	Status	20	—	—	IV
447	Grass Knot	Grass	Special	20	—	100%	IV
448	Chatter	Flying	Special	20	65*	100%	IV
449	Judgment	Normal	Special	10	100	100%	IV
450	Bug Bite	Bug	Physical	20	60	100%	IV
451	Charge Beam	Electric	Special	10	50	90%	IV
452	Wood Hammer	Grass	Physical	15	120	100%	IV
453	Aqua Jet	Water	Physical	20	40	100%	IV
454	Attack Order	Bug	Physical	15	90	100%	IV
455	Defend Order	Bug	Status	10	—	—	IV
456	Heal Order	Bug	Status	10	—	—	IV
457	Head Smash	Rock	Physical	5	150	80%	IV
458	Double Hit	Normal	Physical	10	35	90%	IV
459	Roar of Time	Dragon	Special	5	150	90%	IV
460	Spacial Rend	Dragon	Special	5	100	95%	IV
461	Lunar Dance	Psychic	Status	10	—	—	IV
462	Crush Grip	Normal	Physical	5	—	100%	IV
463	Magma Storm	Fire	Special	5	100*	75%*	IV
464	Dark Void	Dark	Status	10	—	50%*	IV
465	Seed Flare	Grass	Special	5	120	85%	IV
466	Ominous Wind	Ghost	Special	5	60	100%	IV
467	Shadow Force	Ghost	Physical	5	120	100%	IV
468	Hone Claws	Dark	Status	15	—	—	V
469	Wide Guard	Rock	Status	10	—	—	V
470	Guard Split	Psychic	Status	10	—	—	V
471	Power Split	Psychic	Status	10	—	—	V
472	Wonder Room	Psychic	Status	10	—	—	V
473	Psyshock	Psychic	Special	10	80	100%	V
474	Venoshock	Poison	Special	10	65	100%	V
475	Autotomize	Steel	Status	15	—	—	V
476	Rage Powder	Bug	Status	20	—	—	V
477	Telekinesis	Psychic	Status	15	—	—	V
478	Magic Room	Psychic	Status	10	—	—	V
479	Smack Down	Rock	Physical	15	50	100%	V
480	Storm Throw	Fighting	Physical	10	60*	100%	V
481	Flame Burst	Fire	Special	15	70	100%	V
482	Sludge Wave	Poison	Special	10	95	100%	V
483	Quiver Dance	Bug	Status	20	—	—	V
484	Heavy Slam	Steel	Physical	10	—	100%	V
485	Synchronoise	Psychic	Special	10*	120*	100%	V
486	Electro Ball	Electric	Special	10	—	100%	V
487	Soak	Water	Status	20	—	100%	V
488	Flame Charge	Fire	Physical	20	50	100%	V
489	Coil	Poison	Status	20	—	—	V
490	Low Sweep	Fighting	Physical	20	65*	100%	V
491	Acid Spray	Poison	Special	20	40	100%	V
492	Foul Play	Dark	Physical	15	95	100%	V
493	Simple Beam	Normal	Status	15	—	100%	V
494	Entrainment	Normal	Status	15	—	100%	V
495	After You	Normal	Status	15	—	—	V
496	Round	Normal	Special	15	60	100%	V
497	Echoed Voice	Normal	Special	15	40	100%	V
498	Chip Away	Normal	Physical	20	70	100%	V
499	Clear Smog	Poison	Special	15	50	—	V
500	Stored Power	Psychic	Special	10	20	100%	V
501	Quick Guard	Fighting	Status	15	—	—	V
502	Ally Switch	Psychic	Status	15	—	—	V
503	Scald	Water	Special	15	80	100%	V
504	Shell Smash	Normal	Status	15	—	—	V
505	Heal Pulse	Psychic	Status	10	—	—	V
506	Hex	Ghost	Special	10	65*	100%	V
507	Sky Drop	Flying	Physical	10	60	100%	V
508	Shift Gear	Steel	Status	10	—	—	V
509	Circle Throw	Fighting	Physical	10	60	90%	V
510	Incinerate	Fire	Special	15	60*	100%	V
511	Quash	Dark	Status	15	—	100%	V
512	Acrobatics	Flying	Physical	15	55	100%	V
513	Reflect Type	Normal	Status	15	—	—	V
514	Retaliate	Normal	Physical	5	70	100%	V
515	Final Gambit	Fighting	Special	5	—	100%	V
516	Bestow	Normal	Status	15	—	—	V
517	Inferno	Fire	Special	5	100	50%	V
518	Water Pledge	Water	Special	10	80*	100%	V
519	Fire Pledge	Fire	Special	10	80*	100%	V
520	Grass Pledge	Grass	Special	10	80*	100%	V
521	Volt Switch	Electric	Special	20	70	100%	V
522	Struggle Bug	Bug	Special	20	50*	100%	V
523	Bulldoze	Ground	Physical	20	60	100%	V
524	Frost Breath	Ice	Special	10	60*	90%	V
525	Dragon Tail	Dragon	Physical	10	60	90%	V
526	Work Up	Normal	Status	30	—	—	V
527	Electroweb	Electric	Special	15	55	95%	V
528	Wild Charge	Electric	Physical	15	90	100%	V
529	Drill Run	Ground	Physical	10	80	95%	V
530	Dual Chop	Dragon	Physical	15	40	90%	V
531	Heart Stamp	Psychic	Physical	25	60	100%	V
532	Horn Leech	Grass	Physical	10	75	100%	V
533	Sacred Sword	Fighting	Physical	15*	90	100%	V
534	Razor Shell	Water	Physical	10	75	95%	V
535	Heat Crash	Fire	Physical	10	—	100%	V
536	Leaf Tornado	Grass	Special	10	65	90%	V
537	Steamroller	Bug	Physical	20	65	100%	V
538	Cotton Guard	Grass	Status	10	—	—	V
539	Night Daze	Dark	Special	10	85	95%	V
540	Psystrike	Psychic	Special	10	100	100%	V
541	Tail Slap	Normal	Physical	10	25	85%	V
542	Hurricane	Flying	Special	10	110*	70%	V
543	Head Charge	Normal	Physical	15	120	100%	V
544	Gear Grind	Steel	Physical	15	50	85%	V
545	Searing Shot	Fire	Special	5	100	100%	V
546	Techno Blast	Normal	Special	5	120*	100%	V
547	Relic Song	Normal	Special	10	75	100%	V
548	Secret Sword	Fighting	Special	10	85	100%	V
549	Glaciate	Ice	Special	10	65	95%	V
550	Bolt Strike	Electric	Physical	5	130	85%	V
551	Blue Flare	Fire	Special	5	130	85%	V
552	Fiery Dance	Fire	Special	10	80	100%	V
553	Freeze Shock	Ice	Physical	5	140	90%	V
554	Ice Burn	Ice	Special	5	140	90%	V
555	Snarl	Dark	Special	15	55	95%	V
556	Icicle Crash	Ice	Physical	10	85	90%	V
557	V-create	Fire	Physical	5	180	95%	V
558	Fusion Flare	Fire	Special	5	100	100%	V
559	Fusion Bolt	Electric	Physical	5	100	100%	V
560	Flying Press	Fighting	Physical	10	100*	95%	VI
561	Mat Block	Fighting	Status	10	—	—	VI
562	Belch	Poison	Special	10	120	90%	VI
563	Rototiller	Ground	Status	10	—	—	VI
564	Sticky Web	Bug	Status	20	—	—	VI
565	Fell Stinger	Bug	Physical	25	50*	100%	VI
566	Phantom Force	Ghost	Physical	10	90	100%	VI
567	Trick-or-Treat	Ghost	Status	20	—	100%	VI
568	Noble Roar	Normal	Status	30	—	100%	VI
569	Ion Deluge	Electric	Status	25	—	—	VI
570	Parabolic Charge	Electric	Special	20	65*	100%	VI
571	Forest's Curse	Grass	Status	20	—	100%	VI
572	Petal Blizzard	Grass	Physical	15	90	100%	VI
573	Freeze-Dry	Ice	Special	20	70	100%	VI
574	Disarming Voice	Fairy	Special	15	40	—	VI
575	Parting Shot	Dark	Status	20	—	100%	VI
576	Topsy-Turvy	Dark	Status	20	—	—*	VI
577	Draining Kiss	Fairy	Special	10	50	100%	VI
578	Crafty Shield	Fairy	Status	10	—	—	VI
579	Flower Shield	Fairy	Status	10	—	—	VI
580	Grassy Terrain	Grass	Status	10	—	—	VI
581	Misty Terrain	Fairy	Status	10	—	—	VI
582	Electrify	Electric	Status	20	—	—	VI
583	Play Rough	Fairy	Physical	10	90	90%	VI
584	Fairy Wind	Fairy	Special	30	40	100%	VI
585	Moonblast	Fairy	Special	15	95	100%	VI
586	Boomburst	Normal	Special	10	140	100%	VI
587	Fairy Lock	Fairy	Status	10	—	—	VI
588	King's Shield	Steel	Status	10	—	—	VI
589	Play Nice	Normal	Status	20	—	—	VI
590	Confide	Normal	Status	20	—	—	VI
591	Diamond Storm	Rock	Physical	5	100	95%	VI
592	Steam Eruption	Water	Special	5	110	95%	VI
593	Hyperspace Hole	Psychic	Special	5	80	—	VI
594	Water Shuriken*	Water	Special	20	15	100%	VI
595	Mystical Fire	Fire	Special	10	75*	100%	VI
596	Spiky Shield	Grass	Status	10	—	—	VI
597	Aromatic Mist	Fairy	Status	20	—	—	VI
598	Eerie Impulse	Electric	Status	15	—	100%	VI
599	Venom Drench	Poison	Status	20	—	100%	VI
600	Powder	Bug	Status	20	—	100%	VI
601	Geomancy	Fairy	Status	10	—	—	VI
602	Magnetic Flux	Electric	Status	20	—	—	VI
603	Happy Hour	Normal	Status	30	—	—	VI
604	Electric Terrain	Electric	Status	10	—	—	VI
605	Dazzling Gleam	Fairy	Special	10	80	100%	VI
606	Celebrate	Normal	Status	40	—	—	VI
607	Hold Hands	Normal	Status	40	—	—	VI
608	Baby-Doll Eyes	Fairy	Status	30	—	100%	VI
609	Nuzzle	Electric	Physical	20	20	100%	VI
610	Hold Back	Normal	Physical	40	40	100%	VI
611	Infestation	Bug	Special	20	20	100%	VI
612	Power-Up Punch	Fighting	Physical	20	40	100%	VI
613	Oblivion Wing	Flying	Special	10	80	100%	VI
614	Thousand Arrows	Ground	Physical	10	90	100%	VI
615	Thousand Waves	Ground	Physical	10	90	100%	VI
616	Land's Wrath	Ground	Physical	10	90	100%	VI
617	Light of Ruin	Fairy	Special	5	140	90%	VI
618	Origin Pulse	Water	Special	10	110	85%	VI*
619	Precipice Blades	Ground	Physical	10	120	85%	VI*
620	Dragon Ascent	Flying	Physical	5	120	100%	VI*
621	Hyperspace Fury	Dark	Physical	5	100	—	VI*
622	Breakneck Blitz	Normal	Physical	1	—	—	VII
623	Breakneck Blitz	Normal	Special	1	—	—	VII
624	All-Out Pummeling	Fighting	Physical	1	—	—	VII
625	All-Out Pummeling	Fighting	Special	1	—	—	VII
626	Supersonic Skystrike	Flying	Physical	1	—	—	VII
627	Supersonic Skystrike	Flying	Special	1	—	—	VII
628	Acid Downpour	Poison	Physical	1	—	—	VII
629	Acid Downpour	Poison	Special	1	—	—	VII
630	Tectonic Rage	Ground	Physical	1	—	—	VII
631	Tectonic Rage	Ground	Special	1	—	—	VII
632	Continental Crush	Rock	Physical	1	—	—	VII
633	Continental Crush	Rock	Special	1	—	—	VII
634	Savage Spin-Out	Bug	Physical	1	—	—	VII
635	Savage Spin-Out	Bug	Special	1	—	—	VII
636	Never-Ending Nightmare	Ghost	Physical	1	—	—	VII
637	Never-Ending Nightmare	Ghost	Special	1	—	—	VII
638	Corkscrew Crash	Steel	Physical	1	—	—	VII
639	Corkscrew Crash	Steel	Special	1	—	—	VII
640	Inferno Overdrive	Fire	Physical	1	—	—	VII
641	Inferno Overdrive	Fire	Special	1	—	—	VII
642	Hydro Vortex	Water	Physical	1	—	—	VII
643	Hydro Vortex	Water	Special	1	—	—	VII
644	Bloom Doom	Grass	Physical	1	—	—	VII
645	Bloom Doom	Grass	Special	1	—	—	VII
646	Gigavolt Havoc	Electric	Physical	1	—	—	VII
647	Gigavolt Havoc	Electric	Special	1	—	—	VII
648	Shattered Psyche	Psychic	Physical	1	—	—	VII
649	Shattered Psyche	Psychic	Special	1	—	—	VII
650	Subzero Slammer	Ice	Physical	1	—	—	VII
651	Subzero Slammer	Ice	Special	1	—	—	VII
652	Devastating Drake	Dragon	Physical	1	—	—	VII
653	Devastating Drake	Dragon	Special	1	—	—	VII
654	Black Hole Eclipse	Dark	Physical	1	—	—	VII
655	Black Hole Eclipse	Dark	Special	1	—	—	VII
656	Twinkle Tackle	Fairy	Physical	1	—	—	VII
657	Twinkle Tackle	Fairy	Special	1	—	—	VII
658	Catastropika	Electric	Physical	1	210	—	VII
659	Shore Up	Ground	Status	5*	—	—	VII
660	First Impression	Bug	Physical	10	90	100%	VII
661	Baneful Bunker	Poison	Status	10	—	—	VII
662	Spirit Shackle	Ghost	Physical	10	80	100%	VII
663	Darkest Lariat	Dark	Physical	10	85	100%	VII
664	Sparkling Aria	Water	Special	10	90	100%	VII
665	Ice Hammer	Ice	Physical	10	100	90%	VII
666	Floral Healing	Fairy	Status	10	—	—	VII
667	High Horsepower	Ground	Physical	10	95	95%	VII
668	Strength Sap	Grass	Status	10	—	100%	VII
669	Solar Blade	Grass	Physical	10	125	100%	VII
670	Leafage	Grass	Physical	40	40	100%	VII
671	Spotlight	Normal	Status	15	—	—	VII
672	Toxic Thread	Poison	Status	20	—	100%	VII
673	Laser Focus	Normal	Status	30	—	—	VII
674	Gear Up	Steel	Status	20	—	—	VII
675	Throat Chop	Dark	Physical	15	80	100%	VII
676	Pollen Puff	Bug	Special	15	90	100%	VII
677	Anchor Shot	Steel	Physical	20	80	100%	VII
678	Psychic Terrain	Psychic	Status	10	—	—	VII
679	Lunge	Bug	Physical	15	80	100%	VII
680	Fire Lash	Fire	Physical	15	80	100%	VII
681	Power Trip	Dark	Physical	10	20	100%	VII
682	Burn Up	Fire	Special	5	130	100%	VII
683	Speed Swap	Psychic	Status	10	—	—	VII
684	Smart Strike	Steel	Physical	10	70	—	VII
685	Purify	Poison	Status	20	—	—	VII
686	Revelation Dance	Normal	Special	15	90	100%	VII
687	Core Enforcer	Dragon	Special	10	100	100%	VII
688	Trop Kick	Grass	Physical	15	70	100%	VII
689	Instruct	Psychic	Status	15	—	—	VII
690	Beak Blast	Flying	Physical	15	100	100%	VII
691	Clanging Scales	Dragon	Special	5	110	100%	VII
692	Dragon Hammer	Dragon	Physical	15	90	100%	VII
693	Brutal Swing	Dark	Physical	20	60	100%	VII
694	Aurora Veil	Ice	Status	20	—	—	VII
695	Sinister Arrow Raid	Ghost	Physical	1	180	—	VII
696	Malicious Moonsault	Dark	Physical	1	180	—	VII
697	Oceanic Operetta	Water	Special	1	195	—	VII
698	Guardian of Alola	Fairy	Special	1	—	—	VII
699	Soul-Stealing 7-Star Strike	Ghost	Physical	1	195	—	VII
700	Stoked Sparksurfer	Electric	Special	1	175	—	VII
701	Pulverizing Pancake	Normal	Physical	1	210	—	VII
702	Extreme Evoboost	Normal	Status	1	—	—	VII
703	Genesis Supernova	Psychic	Special	1	185	—	VII
704	Shell Trap	Fire	Special	5	150	100%	VII
705	Fleur Cannon	Fairy	Special	5	130	90%	VII
706	Psychic Fangs	Psychic	Physical	10	85	100%	VII
707	Stomping Tantrum	Ground	Physical	10	75	100%	VII
708	Shadow Bone	Ghost	Physical	10	85	100%	VII
709	Accelerock	Rock	Physical	20	40	100%	VII
710	Liquidation	Water	Physical	10	85	100%	VII
711	Prismatic Laser	Psychic	Special	10	160	100%	VII
712	Spectral Thief	Ghost	Physical	10	90	100%	VII
713	Sunsteel Strike	Steel	Physical	5	100	100%	VII
714	Moongeist Beam	Ghost	Special	5	100	100%	VII
715	Tearful Look	Normal	Status	20	—	—	VII
716	Zing Zap	Electric	Physical	10	80	100%	VII
717	Nature's Madness	Fairy	Special	10	—	90%	VII
718	Multi-Attack	Normal	Physical	10	120*	100%	VII
719	10,000,000 Volt Thunderbolt	Electric	Special	1	195	—	VII
720	Mind Blown	Fire	Special	5	150	100%	VII*
721	Plasma Fists	Electric	Physical	15	100	100%	VII*
722	Photon Geyser	Psychic	Special	5	100	100%	VII*
723	Light That Burns the Sky	Psychic	Special	1	200	—	VII*
724	Searing Sunraze Smash	Steel	Physical	1	200	—	VII*
725	Menacing Moonraze Maelstrom	Ghost	Special	1	200	—	VII*
726	Let's Snuggle Forever	Fairy	Physical	1	190	—	VII*
727	Splintered Stormshards	Rock	Physical	1	190	—	VII*
728	Clangorous Soulblaze	Dragon	Special	1	185	—	VII*
729	Zippy Zap	Electric	Physical	10*	80*	100%	VII*
730	Splishy Splash	Water	Special	15	90	100%	VII*
731	Floaty Fall	Flying	Physical	15	90	95%	VII*
732	Pika Papow	Electric	Special	20	—	—	VII*
733	Bouncy Bubble	Water	Special	20*	60*	100%	VII*
734	Buzzy Buzz	Electric	Special	20*	60*	100%	VII*
735	Sizzly Slide	Fire	Physical	20*	60*	100%	VII*
736	Glitzy Glow	Psychic	Special	15	80*	95%*	VII*
737	Baddy Bad	Dark	Special	15	80*	95%*	VII*
738	Sappy Seed	Grass	Physical	10*	100*	90%*	VII*
739	Freezy Frost	Ice	Special	10*	100*	90%*	VII*
740	Sparkly Swirl	Fairy	Special	5*	120*	85%*	VII*
741	Veevee Volley	Normal	Physical	20	—	—	VII*
742	Double Iron Bash	Steel	Physical	5	60	100%	VII*
743	Max Guard	Normal	Status	10	—	—	VIII
744	Dynamax Cannon	Dragon	Special	5	100	100%	VIII
745	Snipe Shot	Water	Special	15	80	100%	VIII
746	Jaw Lock	Dark	Physical	10	80	100%	VIII
747	Stuff Cheeks	Normal	Status	10	—	—	VIII
748	No Retreat	Fighting	Status	5	—	—	VIII
749	Tar Shot	Rock	Status	15	—	100%	VIII
750	Magic Powder	Psychic	Status	20	—	100%	VIII
751	Dragon Darts	Dragon	Physical	10	50	100%	VIII
752	Teatime	Normal	Status	10	—	—	VIII
753	Octolock	Fighting	Status	15	—	100%	VIII
754	Bolt Beak	Electric	Physical	10	85	100%	VIII
755	Fishious Rend	Water	Physical	10	85	100%	VIII
756	Court Change	Normal	Status	10	—	100%	VIII
757	Max Flare	Fire	???	10	—	—	VIII
758	Max Flutterby	Bug	???	10	—	—	VIII
759	Max Lightning	Electric	???	10	—	—	VIII
760	Max Strike	Normal	???	10	—	—	VIII
761	Max Knuckle	Fighting	???	10	—	—	VIII
762	Max Phantasm	Ghost	???	10	—	—	VIII
763	Max Hailstorm	Ice	???	10	—	—	VIII
764	Max Ooze	Poison	???	10	—	—	VIII
765	Max Geyser	Water	???	10	—	—	VIII
766	Max Airstream	Flying	???	10	—	—	VIII
767	Max Starfall	Fairy	???	10	—	—	VIII
768	Max Wyrmwind	Dragon	???	10	—	—	VIII
769	Max Mindstorm	Psychic	???	10	—	—	VIII
770	Max Rockfall	Rock	???	10	—	—	VIII
771	Max Quake	Ground	???	10	—	—	VIII
772	Max Darkness	Dark	???	10	—	—	VIII
773	Max Overgrowth	Grass	???	10	—	—	VIII
774	Max Steelspike	Steel	???	10	—	—	VIII
775	Clangorous Soul	Dragon	Status	5	—	—	VIII
776	Body Press	Fighting	Physical	10	80	100%	VIII
777	Decorate	Fairy	Status	15	—	—	VIII
778	Drum Beating	Grass	Physical	10	80	100%	VIII
779	Snap Trap	Grass	Physical	15	35	100%	VIII
780	Pyro Ball	Fire	Physical	5	120	90%	VIII
781	Behemoth Blade	Steel	Physical	5	100	100%	VIII
782	Behemoth Bash	Steel	Physical	5	100	100%	VIII
783	Aura Wheel	Electric	Physical	10	110	100%	VIII
784	Breaking Swipe	Dragon	Physical	15	60	100%	VIII
785	Branch Poke	Grass	Physical	40	40	100%	VIII
786	Overdrive	Electric	Special	10	80	100%	VIII
787	Apple Acid	Grass	Special	10	80	100%	VIII
788	Grav Apple	Grass	Physical	10	80	100%	VIII
789	Spirit Break	Fairy	Physical	15	75	100%	VIII
790	Strange Steam	Fairy	Special	10	90	95%	VIII
791	Life Dew	Water	Status	10	—	—	VIII
792	Obstruct	Dark	Status	10	—	100%	VIII
793	False Surrender	Dark	Physical	10	80	—	VIII
794	Meteor Assault	Fighting	Physical	5	150	100%	VIII
795	Eternabeam	Dragon	Special	5	160	90%	VIII
796	Steel Beam	Steel	Special	5	140	95%	VIII
797	Expanding Force	Psychic	Special	10	80	100%	VIII
798	Steel Roller	Steel	Physical	5	130	100%	VIII
799	Scale Shot	Dragon	Physical	20	25	90%	VIII
800	Meteor Beam	Rock	Special	10	120	90%	VIII
801	Shell Side Arm	Poison	Special	10	90	100%	VIII
802	Misty Explosion	Fairy	Special	5	100	100%	VIII
803	Grassy Glide	Grass	Physical	20	70	100%	VIII
804	Rising Voltage	Electric	Special	20	70	100%	VIII
805	Terrain Pulse	Normal	Special	10	50	100%	VIII
806	Skitter Smack	Bug	Physical	10	70	90%	VIII
807	Burning Jealousy	Fire	Special	5	70	100%	VIII
808	Lash Out	Dark	Physical	5	75	100%	VIII
809	Poltergeist	Ghost	Physical	5	110	90%	VIII
810	Corrosive Gas	Poison	Status	40	—	100%	VIII
811	Coaching	Fighting	Status	10	—	—	VIII
812	Flip Turn	Water	Physical	20	60	100%	VIII
813	Triple Axel	Ice	Physical	10	20	90%	VIII
814	Dual Wingbeat	Flying	Physical	10	40	90%	VIII
815	Scorching Sands	Ground	Special	10	70	100%	VIII
816	Jungle Healing	Grass	Status	10	—	—	VIII
817	Wicked Blow	Dark	Physical	5	80	100%	VIII
818	Surging Strikes	Water	Physical	5	25	100%	VIII
819	Thunder Cage	Electric	Special	15	80	90%	VIII
820	Dragon Energy	Dragon	Special	5	150	100%	VIII
821	Freezing Glare	Psychic	Special	10	90	100%	VIII
822	Fiery Wrath	Dark	Special	10	90	100%	VIII
823	Thunderous Kick	Fighting	Physical	10	90	100%	VIII
824	Glacial Lance	Ice	Physical	5	130	100%	VIII
825	Astral Barrage	Ghost	Special	5	120	100%	VIII
826	Eerie Spell	Psychic	Special	5	80	100%	VIII
""".strip()

rows = [row.split('\t') for row in data.split('\n')]
name = "MOVE"

with open(f"src/mod/data/{name.lower()}s.h", "w") as f:
    f.write("#pragma once\n\n")
    f.write(f"const char *{name}S[] = {{\n")
    for row in rows:
        id, move, type, category, pp, power, accuracy, gen = row
        f.write(f'    "{move}",\n')
    f.write("};\n\n")
    f.write(f"const int {name}_COUNT = sizeof({name}S) / sizeof({name}S[0]);\n")
