defmodule Words do
  @doc """
  Count the number of words in the sentence.

  Words are compared case-insensitively.
  """
  @spec count(String.t()) :: map
  def count(sentence) do
    sentence = String.replace(sentence, "_", " ")               # underscores
    sentence = String.replace(sentence, ",", " ")               # commas
    sentence = String.replace(sentence, ~r/[\:\^&*%#$!@]/, " ") # punctuation
    words = String.split(String.downcase(sentence))
    Enum.reduce(words, %{}, fn (w, acc) ->
      Map.put(acc, w, Map.get(acc, w, 0) + 1)
    end)
  end
end
