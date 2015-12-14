#include <gtest/gtest.h>
#include "minimum_height_tree.cpp"

class MinimumHeightTreeTest: public testing::Test{
    protected:
        CutSolution sol;
};
TEST_F(MinimumHeightTreeTest, Small){
    PII a[] = {MP(0,1),};
    vector<PII> nums(ASZ(a));
    int z[] = {0,1};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.findMinHeightTrees(2, nums));
}
TEST_F(MinimumHeightTreeTest, Small2){
    PII a[] = {MP(0,1),MP(1,2),MP(1,3),};
    vector<PII> nums(ASZ(a));
    int z[] = {1};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.findMinHeightTrees(4, nums));
}
TEST_F(MinimumHeightTreeTest, Small3){
    PII a[] = {MP(0,3),MP(1,3),MP(2,3),MP(3,4),MP(4,5),};
    vector<PII> nums(ASZ(a));
    int z[] = {3,4};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.findMinHeightTrees(6, nums));
}
TEST_F(MinimumHeightTreeTest, Big){
    PII a[] = {MP(0,1),MP(0,2),MP(2,3),MP(3,4),MP(4,5),MP(1,6),MP(1,7),MP(5,8),MP(2,9),MP(7,10),MP(8,11),MP(8,12),MP(3,13),MP(6,14),MP(13,15),MP(4,16),MP(14,17),MP(14,18),MP(9,19),MP(12,20),MP(6,21),MP(14,22),MP(8,23),MP(20,24),MP(13,25),MP(21,26),MP(6,27),MP(15,28),MP(16,29),MP(27,30),MP(21,31),MP(9,32),MP(13,33),MP(15,34),MP(26,35),MP(19,36),MP(16,37),MP(14,38),MP(13,39),MP(11,40),MP(5,41),MP(7,42),MP(33,43),MP(19,44),MP(2,45),MP(26,46),MP(42,47),MP(21,48),MP(10,49),MP(18,50),MP(8,51),MP(19,52),MP(22,53),MP(47,54),MP(47,55),MP(19,56),MP(5,57),MP(49,58),MP(42,59),MP(13,60),MP(36,61),MP(22,62),MP(43,63),MP(2,64),MP(41,65),MP(32,66),MP(33,67),MP(64,68),MP(32,69),MP(26,70),MP(52,71),MP(52,72),MP(4,73),MP(29,74),MP(26,75),MP(5,76),MP(28,77),MP(29,78),MP(2,79),MP(63,80),MP(72,81),MP(62,82),MP(68,83),MP(33,84),MP(23,85),MP(17,86),MP(22,87),MP(22,88),MP(4,89),MP(41,90),MP(29,91),MP(31,92),MP(24,93),MP(1,94),MP(45,95),MP(60,96),MP(28,97),MP(46,98),MP(27,99),MP(32,100),MP(75,101),MP(2,102),MP(12,103),MP(67,104),MP(19,105),MP(96,106),MP(101,107),MP(17,108),MP(78,109),MP(18,110),MP(24,111),MP(95,112),MP(106,113),MP(102,114),MP(55,115),MP(78,116),MP(76,117),MP(91,118),MP(19,119),MP(89,120),MP(64,121),MP(49,122),MP(107,123),MP(18,124),MP(93,125),MP(79,126),MP(51,127),MP(97,128),MP(112,129),MP(82,130),MP(116,131),MP(4,132),MP(105,133),MP(104,134),MP(117,135),MP(19,136),MP(13,137),MP(134,138),MP(92,139),MP(111,140),MP(87,141),MP(36,142),MP(106,143),MP(91,144),MP(21,145),MP(127,146),MP(17,147),MP(58,148),MP(13,149),MP(88,150),MP(66,151),MP(136,152),MP(48,153),MP(104,154),MP(7,155),MP(97,156),MP(76,157),MP(36,158),MP(152,159),MP(116,160),MP(39,161),MP(130,162),MP(119,163),MP(162,164),MP(128,165),MP(57,166),MP(17,167),MP(25,168),MP(166,169),MP(31,170),MP(160,171),MP(16,172),MP(105,173),MP(24,174),MP(130,175),MP(133,176),MP(143,177),MP(41,178),MP(137,179),MP(10,180),MP(151,181),MP(22,182),MP(101,183),MP(86,184),MP(82,185),MP(42,186),MP(85,187),MP(96,188),MP(165,189),MP(73,190),MP(40,191),MP(95,192),MP(192,193),MP(93,194),MP(170,195),MP(168,196),MP(182,197),MP(176,198),MP(142,199),MP(169,200),MP(168,201),MP(1,202),MP(148,203),MP(35,204),MP(54,205),MP(132,206),MP(103,207),MP(2,208),MP(81,209),MP(161,210),MP(95,211),MP(133,212),MP(43,213),MP(63,214),MP(15,215),MP(185,216),MP(20,217),MP(161,218),MP(28,219),MP(196,220),MP(71,221),MP(92,222),MP(151,223),MP(207,224),MP(42,225),MP(31,226),MP(6,227),MP(33,228),MP(207,229),MP(29,230),MP(143,231),MP(231,232),MP(38,233),MP(62,234),MP(176,235),MP(4,236),MP(92,237),MP(32,238),MP(66,239),MP(6,240),MP(121,241),MP(116,242),MP(49,243),MP(224,244),MP(189,245),MP(28,246),MP(157,247),MP(115,248),MP(20,249),MP(239,250),MP(106,251),MP(172,252),MP(242,253),MP(48,254),MP(234,255),MP(140,256),MP(40,257),MP(157,258),MP(236,259),MP(198,260),MP(62,261),MP(179,262),MP(78,263),MP(22,264),MP(91,265),MP(254,266),MP(60,267),MP(243,268),MP(100,269),MP(207,270),MP(194,271),MP(84,272),MP(87,273),MP(166,274),MP(234,275),MP(133,276),MP(130,277),MP(23,278),MP(97,279),MP(169,280),MP(29,281),MP(232,282),MP(254,283),MP(168,284),MP(126,285),MP(284,286),MP(59,287),MP(77,288),MP(173,289),MP(79,290),MP(254,291),MP(273,292),MP(208,293),MP(288,294),MP(109,295),MP(139,296),MP(231,297),MP(91,298),MP(210,299),MP(81,300),MP(268,301),MP(225,302),MP(296,303),MP(241,304),MP(60,305),MP(90,306),MP(284,307),MP(130,308),MP(297,309),MP(218,310),MP(209,311),MP(70,312),MP(252,313),MP(188,314),MP(175,315),MP(172,316),MP(275,317),MP(313,318),MP(117,319),MP(291,320),MP(178,321),MP(11,322),MP(141,323),MP(173,324),MP(75,325),MP(165,326),MP(77,327),MP(106,328),MP(191,329),MP(217,330),MP(74,331),MP(129,332),MP(124,333),MP(242,334),MP(161,335),MP(289,336),MP(138,337),MP(101,338),MP(257,339),MP(162,340),MP(154,341),MP(110,342),MP(126,343),MP(152,344),MP(312,345),MP(317,346),MP(147,347),MP(145,348),MP(328,349),MP(314,350),MP(276,351),MP(238,352),MP(164,353),MP(161,354),MP(347,355),MP(158,356),MP(187,357),MP(325,358),MP(113,359),MP(207,360),MP(276,361),MP(92,362),MP(313,363),MP(147,364),MP(88,365),MP(307,366),MP(96,367),MP(328,368),MP(187,369),MP(99,370),MP(13,371),MP(262,372),MP(248,373),MP(247,374),MP(42,375),MP(9,376),MP(282,377),MP(35,378),MP(284,379),MP(338,380),MP(325,381),MP(100,382),MP(341,383),MP(274,384),MP(309,385),MP(297,386),MP(352,387),MP(273,388),MP(140,389),MP(257,390),MP(4,391),MP(366,392),MP(331,393),MP(158,394),MP(13,395),MP(112,396),MP(131,397),MP(12,398),};
    vector<PII> nums(ASZ(a));
    int z[] = {0,2};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.findMinHeightTrees(399, nums));
}
TEST_F(MinimumHeightTreeTest, Big2){
    PII a[] = {MP(0,1),MP(0,2),MP(2,3),MP(0,4),MP(1,5),MP(2,6),MP(4,7),MP(5,8),MP(5,9),MP(4,10),MP(5,11),MP(8,12),MP(6,13),MP(9,14),MP(1,15),MP(6,16),MP(14,17),MP(3,18),MP(4,19),MP(14,20),MP(9,21),MP(16,22),MP(6,23),MP(7,24),MP(9,25),MP(13,26),MP(1,27),MP(17,28),MP(25,29),MP(0,30),MP(29,31),MP(19,32),MP(5,33),MP(19,34),MP(16,35),MP(19,36),MP(10,37),MP(29,38),MP(9,39),MP(31,40),MP(1,41),MP(1,42),MP(20,43),MP(10,44),MP(20,45),MP(0,46),MP(26,47),MP(10,48),MP(32,49),MP(21,50),MP(5,51),MP(15,52),MP(17,53),MP(39,54),MP(17,55),MP(38,56),MP(38,57),MP(10,58),MP(2,59),MP(4,60),MP(43,61),MP(7,62),MP(15,63),MP(45,64),MP(30,65),MP(41,66),MP(26,67),MP(19,68),MP(2,69),MP(38,70),MP(58,71),MP(20,72),MP(13,73),MP(45,74),MP(55,75),MP(13,76),MP(35,77),MP(17,78),MP(65,79),MP(38,80),MP(15,81),MP(22,82),MP(66,83),MP(20,84),MP(41,85),MP(78,86),MP(82,87),MP(10,88),MP(53,89),MP(10,90),MP(68,91),MP(24,92),MP(65,93),MP(18,94),MP(4,95),MP(26,96),MP(63,97),MP(0,98),MP(70,99),MP(3,100),MP(48,101),MP(41,102),MP(99,103),MP(56,104),MP(10,105),MP(83,106),MP(96,107),MP(8,108),MP(86,109),MP(55,110),MP(72,111),MP(67,112),MP(42,113),MP(63,114),MP(65,115),MP(107,116),MP(29,117),MP(112,118),MP(36,119),MP(55,120),MP(48,121),MP(106,122),MP(31,123),MP(75,124),MP(95,125),MP(8,126),MP(1,127),MP(72,128),MP(70,129),MP(123,130),MP(109,131),MP(46,132),MP(99,133),MP(107,134),MP(48,135),MP(120,136),MP(61,137),MP(7,138),MP(127,139),MP(72,140),MP(132,141),MP(4,142),MP(81,143),MP(85,144),MP(91,145),MP(25,146),MP(88,147),MP(147,148),MP(97,149),MP(145,150),MP(140,151),MP(83,152),MP(71,153),MP(66,154),MP(86,155),MP(48,156),MP(29,157),MP(142,158),MP(13,159),MP(159,160),MP(31,161),MP(66,162),MP(140,163),MP(128,164),MP(129,165),MP(43,166),MP(103,167),MP(136,168),MP(39,169),MP(42,170),MP(154,171),MP(59,172),MP(86,173),MP(61,174),MP(51,175),MP(15,176),MP(139,177),MP(30,178),MP(130,179),MP(165,180),MP(47,181),MP(54,182),MP(68,183),MP(160,184),MP(71,185),MP(39,186),MP(30,187),MP(107,188),MP(43,189),MP(89,190),MP(85,191),MP(183,192),MP(26,193),MP(193,194),MP(172,195),MP(1,196),MP(43,197),MP(178,198),MP(128,199),MP(4,200),MP(150,201),MP(58,202),MP(93,203),MP(183,204),MP(15,205),MP(98,206),MP(131,207),MP(7,208),MP(138,209),MP(129,210),MP(186,211),MP(47,212),MP(66,213),MP(155,214),MP(123,215),MP(75,216),MP(161,217),MP(123,218),MP(190,219),MP(205,220),MP(166,221),MP(44,222),MP(64,223),MP(78,224),MP(125,225),MP(163,226),MP(28,227),MP(26,228),MP(25,229),MP(115,230),MP(68,231),MP(7,232),MP(140,233),MP(7,234),MP(111,235),MP(164,236),MP(43,237),MP(166,238),MP(227,239),MP(95,240),MP(79,241),MP(26,242),MP(196,243),MP(51,244),MP(17,245),MP(53,246),MP(122,247),MP(136,248),MP(170,249),MP(130,250),MP(99,251),MP(93,252),MP(41,253),MP(199,254),MP(66,255),MP(244,256),MP(187,257),MP(202,258),MP(219,259),MP(158,260),MP(112,261),MP(178,262),MP(191,263),MP(223,264),MP(5,265),MP(191,266),MP(78,267),MP(112,268),MP(179,269),MP(141,270),MP(26,271),MP(76,272),MP(106,273),MP(176,274),MP(137,275),MP(36,276),MP(80,277),MP(20,278),MP(57,279),MP(67,280),MP(116,281),MP(14,282),MP(82,283),MP(279,284),MP(7,285),MP(256,286),MP(204,287),MP(137,288),MP(183,289),MP(241,290),MP(67,291),MP(274,292),MP(213,293),MP(149,294),MP(69,295),MP(150,296),MP(156,297),MP(232,298),MP(239,299),MP(293,300),MP(89,301),MP(282,302),MP(88,303),MP(193,304),MP(21,305),MP(185,306),MP(17,307),MP(171,308),MP(261,309),MP(139,310),MP(233,311),MP(207,312),MP(140,313),MP(37,314),MP(241,315),MP(215,316),MP(94,317),MP(4,318),MP(274,319),MP(309,320),MP(105,321),MP(217,322),MP(13,323),MP(204,324),MP(259,325),MP(57,326),MP(95,327),MP(88,328),MP(140,329),MP(176,330),MP(211,331),MP(190,332),MP(142,333),MP(327,334),MP(268,335),MP(132,336),MP(63,337),MP(222,338),MP(272,339),MP(255,340),MP(194,341),MP(307,342),MP(247,343),MP(234,344),MP(38,345),MP(213,346),MP(196,347),MP(298,348),MP(343,349),MP(133,350),MP(100,351),MP(143,352),MP(46,353),MP(40,354),MP(177,355),MP(110,356),MP(331,357),MP(255,358),MP(222,359),MP(123,360),MP(164,361),MP(137,362),MP(27,363),MP(151,364),MP(363,365),MP(131,366),MP(273,367),MP(279,368),MP(101,369),MP(133,370),MP(284,371),MP(100,372),MP(216,373),MP(21,374),MP(51,375),MP(262,376),MP(26,377),MP(176,378),MP(217,379),MP(75,380),MP(332,381),MP(199,382),MP(230,383),MP(380,384),MP(301,385),MP(312,386),MP(385,387),MP(171,388),MP(26,389),MP(0,390),MP(228,391),MP(1,392),MP(164,393),MP(355,394),MP(200,395),MP(113,396),MP(265,397),MP(17,398),MP(184,399),MP(399,400),MP(38,401),MP(356,402),MP(129,403),MP(102,404),MP(326,405),MP(38,406),MP(326,407),MP(391,408),MP(181,409),MP(322,410),MP(366,411),MP(214,412),MP(244,413),MP(305,414),MP(140,415),MP(352,416),MP(314,417),MP(379,418),MP(81,419),MP(388,420),MP(334,421),MP(168,422),MP(69,423),MP(88,424),MP(327,425),MP(404,426),MP(372,427),MP(427,428),MP(397,429),MP(2,430),MP(322,431),MP(16,432),MP(351,433),MP(335,434),MP(291,435),MP(426,436),MP(429,437),MP(143,438),MP(19,439),MP(91,440),MP(206,441),MP(289,442),MP(237,443),MP(404,444),MP(405,445),MP(79,446),MP(85,447),MP(159,448),MP(130,449),MP(281,450),MP(104,451),MP(408,452),MP(405,453),MP(94,454),MP(317,455),MP(202,456),MP(297,457),MP(232,458),MP(341,459),MP(381,460),MP(21,461),MP(127,462),MP(173,463),MP(301,464),MP(300,465),MP(304,466),MP(73,467),MP(439,468),MP(427,469),MP(305,470),MP(153,471),MP(20,472),MP(210,473),MP(105,474),MP(77,475),MP(180,476),MP(233,477),MP(250,478),MP(38,479),MP(412,480),MP(431,481),MP(196,482),MP(344,483),MP(63,484),MP(308,485),MP(236,486),MP(56,487),MP(107,488),MP(114,489),MP(237,490),MP(476,491),MP(440,492),MP(462,493),MP(457,494),MP(204,495),MP(123,496),MP(119,497),MP(393,498),MP(237,499),MP(157,500),MP(265,501),MP(453,502),MP(32,503),MP(151,504),};
    vector<PII> nums(ASZ(a));
    int z[] = {1,5};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.findMinHeightTrees(505, nums));
}