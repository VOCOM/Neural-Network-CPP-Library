# RSE4207
Artificial Intelligence model\
Language: `C++`\
Build system: `CMake`\
Supported Operating Systems: `Windows`, `Linux`

How to use:
1. Download the `inc` folder
2. ```
   /* Neural Net Example */
   #define SigmoidScaler 100

   // Initial Values
   std::vector<std::vector<double>>    weights {{1}};
   std::vector<double>                 inputs  {15};
   std::vector<double>                 outputs {1};
   std::vector<double>                 bias    {10};
   std::shared_ptr<SigmoidActivator<SigmoidScaler>> triggerFunction = std::make_shared<SigmoidActivator<SigmoidScaler>>();

   // Neural Net
   NeuralNet& neuralNet = NeuralNet::Initialise(inputs, outputs);
   // Add Layers
   neuralNet.AddLayer(weights, bias, triggerFunction);
   // Run a Forward Pass
   neuralNet.ForwardPass();
   ```

Library is header based, no linking required.
