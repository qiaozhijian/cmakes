import numpy as np

T_b_c1 = np.asarray([0.0148655429818, -0.999880929698, 0.00414029679422, -0.0216401454975,
                     0.999557249008, 0.0149672133247, 0.025715529948, -0.064676986768,
                     -0.0257744366974, 0.00375618835797, 0.999660727178, 0.00981073058949,
                     0.0, 0.0, 0.0, 1.0]).reshape(4,4)



T_b_c2 = np.asarray([0.0125552670891, -0.999755099723, 0.0182237714554, -0.0198435579556,
                     0.999598781151, 0.0130119051815, 0.0251588363115, 0.0453689425024,
                     -0.0253898008918, 0.0179005838253, 0.999517347078, 0.00786212447038,
                     0.0, 0.0, 0.0, 1.0]).reshape(4,4)

T_c1_c2 = np.asarray([0.9999992350794548, 0.0012154557728128233, -2.2914573879299506E-4,119.7446053075405,
                      -0.001215825251510682, 0.9999979499237537, -0.0016192335371478666,-0.12487470599842067,
                      2.2717716227647425E-4, 0.0016195108997383704, 0.9999986627865971,0.1870855595881091,
                      0.0, 0.0, 0.0, 1.0]).reshape(4,4)

print(T_c1_c2)
print(np.linalg.inv(T_c1_c2))